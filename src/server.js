const App = require('../lib/js/src/app').comp;

import React from 'react';
import compression from 'compression';
import express from 'express';
import helmet from 'helmet';
import hpp from 'hpp';
import morgan from 'morgan';
import path from 'path';
import { renderToString } from 'react-dom/server';

const assets = require(process.env.RAZZLE_ASSETS_MANIFEST);

const server = express();

server
  .disable('x-powered-by')
  .use(morgan('dev'))
  .use(helmet())
  .use(hpp())
  .use(compression())
  .use(express.static(process.env.RAZZLE_PUBLIC_DIR))
  .get('/*', (req, res) => {
    const markup = renderToString(React.createElement(App));
    res.send(
      `<!doctype html>
    <html lang="en">
    <head>
        <meta httpEquiv="X-UA-Compatible" content="IE=edge" />
        <meta charSet='utf-8' />
        <title>ReasonML NYC</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="https://fonts.googleapis.com/css?family=Montserrat:400,700" rel="stylesheet" type="text/css">
        ${assets.client.css ? `<link rel="stylesheet" href="${assets.client.css}">` : ''}
        <script src="${assets.client.js}" defer></script>
    </head>
    <body>
        <div id="root"></div>
    </body>
</html>`
    );
  });

export default server;
