const App = require('../lib/js/src/app').comp;

import 'sanitize.css/sanitize.css';
import './client.css';

import React from 'react';
import { render } from 'react-dom';

render(React.createElement(App), document.getElementById('root'));

if (module.hot) {
  module.hot.accept();
}
