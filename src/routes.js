const HomeNew = require('../lib/js/src/homenew').comp;
const About = require('../lib/js/src/about').comp;

export default [
  {
    component: HomeNew,
    path: '/',
  },
  {
    component: About,
    path: '/about',
  },
];
