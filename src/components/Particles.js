var ReactDOM = require('react-dom');
var React = require('react');

const AMOUNTX = 50;
const AMOUNTY = 40;
const SEPARATION = 40;

var App = React.createClass({
  getInitialState() {
    return {
      count: 0.05,
    };
  },
  componentDidMount() {
    this.animate();
  },
  componentWillUnmount() {
    window.cancelAnimationFrame(this.animate);
  },
  animate() {
    this.container.width = window.innerWidth;
    this.container.height = window.innerHeight;

    this.context = this.container.getContext('2d');
    this.context.clearRect(0, 0, window.innerWidth, window.innerHeight);

    this.context.webkitImageSmoothingEnabled = true;

    for (let iz = 1; iz < 30; iz++) {
      for (let ix = 0; ix < AMOUNTX; ix++) {
        const xSpacing = SEPARATION + iz * 3;
        const ySpacing = (SEPARATION + iz) / 4;
        const xOffset = window.innerWidth - AMOUNTX * xSpacing;
        const amplitude = 2.5 * (30 - iz);

        const x = xOffset / 2.4 + xSpacing * ix;
        const verticalWave = Math.sin(
          (ix / 2 + iz + this.state.count / 2) * 0.3
        );
        const horizontalWave = Math.sin(ix / 2 + this.state.count / 4) * 0.3;
        const y =
          iz * ySpacing + amplitude * verticalWave + 5 * iz * horizontalWave;

        const radius = (2 - verticalWave) * iz / 20;

        this.context.beginPath();
        this.context.arc(x, (y + 200) * 0.7, radius, 0, Math.PI * 2, false);
        this.context.fillStyle = 'rgba(221,75,51,.8)';
        this.context.fill();
      }
    }
    this.setState(state => ({ count: state.count + 0.05 }));
    window.requestAnimationFrame(this.animate);
  },
  render: function() {
    var self = this;
    if (this.props.show) {
      return React.createElement(
        'canvas',
        {
          ref: function(i) {
            self.container = i;
          },
          id: 'canvas-pattern',
          style: { zIndex: 0, position: 'absolute', top: 0, left: 0, right: 0 },
        },
        this.props.message
      );
    } else {
      return null;
    }
  },
});

module.exports = App;
