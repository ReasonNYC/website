import React from 'react';
import StaticRouter from 'react-router-dom/StaticRouter';
import axios from 'axios';
import compression from 'compression';
import express from 'express';
import helmet from 'helmet';
import hpp from 'hpp';
import morgan from 'morgan';
import path from 'path';
import { renderToString } from 'react-dom/server';
import serialize from 'serialize-javascript';

const App = require('../lib/js/src/app').comp;

const assets = require(process.env.RAZZLE_ASSETS_MANIFEST);

const server = express();

server
  .disable('x-powered-by')
  .use(morgan(process.env.NODE_ENV === 'production' ? 'combined' : 'dev'))
  .use(helmet())
  .use(hpp())
  .use(compression())
  .use(express.static(process.env.RAZZLE_PUBLIC_DIR))
  .get('/*', (req, res) => {
    let context = {};
    const markup = renderToString(
      <StaticRouter context={context} location={req.url}>
        <App />
      </StaticRouter>
    );
    res.send(
      `<!doctype html>
    <html lang="en">
    <head>
        <meta httpEquiv="X-UA-Compatible" content="IE=edge" />
        <meta charSet='utf-8' />
        <title>ReasonML NYC</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="description" content="We are the ReasonML community in NYC">
        <meta name="keywords" content="reason,reasonml,react,new york,nyc,2017,red badger,facebook">
        <link rel="shortcut icon" href="/favicon.ico">
        
        <meta name="theme-color" content="#dd4b39">
        
        <!-- Disable tap highlight on IE -->
        <meta name="msapplication-tap-highlight" content="no">

        <!-- Web Application Manifest -->
        <link rel="manifest" href="/manifest.json">

        <!-- Add to homescreen for Chrome on Android -->
        <meta name="mobile-web-app-capable" content="yes">
        <meta name="application-name" content="ReasonML NYC">
        <link rel="icon" sizes="192x192" href="/icon-192x192.png">

        <!-- Add to homescreen for Safari on iOS -->
        <meta name="apple-mobile-web-app-capable" content="yes">
        <meta name="apple-mobile-web-app-status-bar-style" content="black">
        <meta name="apple-mobile-web-app-title" content="ReasonML NYC">
        <link rel="apple-touch-icon" href="/icon-144x144-precomposed.png">

        <!-- Tile icon for Win8 (144x144 + tile color) -->
        <meta name="msapplication-TileImage" content="/icon-144x144-precomposed.png">
        <meta name="msapplication-TileColor" content="#F6F4F4">

        <meta property="og:url" content="https://reason.nyc">
        <meta property="og:type" content="website">
        <meta property="og:title" content="ReasonML NYC">
        <meta property="og:image" content="https://reason.nyc/og_image.png">
        <meta property="og:description" content="We are the ReasonML community in NYC">

        <meta name="twitter:card" content="summary_large_image"/>
        <meta name="twitter:site" content="@NYCReasonML"/>
        <meta name="twitter:title" content="ReasonML NYC"/>
        <meta name="twitter:description" content="We are the ReasonML community in NYC">
        <meta name="twitter:image" content="https://reason.nyc/twitter_card.png">

        <meta name="google-site-verification" content="HybV-uz0nBNE_kOtoiUvW2I4b2GCE43SDwk-w86rgsM" />
        
        <link href="https://fonts.googleapis.com/css?family=Montserrat:400,700" rel="stylesheet" type="text/css">
        ${assets.client.css
          ? `<link rel="stylesheet" href="${assets.client.css}">`
          : ''}
        <script src="${assets.client.js}" defer></script>
    </head>
    <body>
        <div id="root">${markup}</div>
        <script>window.__DATA__ = ${serialize({})};</script>
    </body>
</html>`
    );
  });

export default server;
