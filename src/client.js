const App = require('../lib/js/src/app').comp;

import 'sanitize.css/sanitize.css';
import './global.css';
import './Wrapper.css';
import './App.css';
import './Button.css';
import './EventItem.css';

import Particles from './Particles';
import React from 'react';
import registerServiceWorker from './registerServiceWorker';
import { render } from 'react-dom';

render(
  React.createElement(App, window.__DATA__),
  document.getElementById('root')
);
registerServiceWorker();

if (module.hot) {
  module.hot.accept();
}
