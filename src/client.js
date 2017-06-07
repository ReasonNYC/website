import 'sanitize.css/sanitize.css';
import './global.css';
import './components/Wrapper.css';
import './components/Icon.css';
import './components/Button.css';
import './components/EventItem.css';
import './components/Speaker.css';
import './pages/Home.css';

import BrowserRouter from 'react-router-dom/BrowserRouter';
import React from 'react';
import registerServiceWorker from './utils/registerServiceWorker';
import { render } from 'react-dom';

const App = require('../lib/js/src/app').comp;

const initialState = window.__DATA__;

render(
  <BrowserRouter>
    <App />
  </BrowserRouter>,
  document.getElementById('root')
);

registerServiceWorker();

if (module.hot) {
  module.hot.accept();
}
