'use strict';

const SWPrecacheWebpackPlugin = require('sw-precache-webpack-plugin');
const path = require('path');

module.exports = {
  modify(config, { target, dev}, webpack) {
    if (target === 'web' && !dev) {
      config.plugins.push(new SWPrecacheWebpackPlugin({
          // By default, a cache-busting query parameter is appended to requests
          // used to populate the caches, to ensure the responses are fresh.
          // If a URL is already hashed by Webpack, then there is no concern
          // about it being stale, and the cache-busting can be skipped.
          dontCacheBustUrlsMatching: /\.\w{8}\./,
          filename: 'service-worker.js',
          logger(message) {
            if (message.indexOf('Total precache size is') === 0) {
              // This message occurs for every build and is a bit too noisy.
              return;
            }
            console.log(message);
          },
          minify: true,
          navigateFallback: '' + '/index.html',
          staticFileGlobsIgnorePatterns: [
            /\.map$/,
            /asset-manifest\.json$/,
            /assets\.json$/,
          ],
          // Work around Windows path issue in SWPrecacheWebpackPlugin:
          // https://github.com/facebookincubator/create-react-app/issues/2235
          stripPrefix: path.join(__dirname, './build').replace(/\\/g, '/') + '/',
        }))
    }
    return config;
  }
}