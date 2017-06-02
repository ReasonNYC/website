/**
 * Not Used, just for an example.
 * This is Stateless Functional Component equivalent that is just for CSS.
 */
module About = {
  include ReactRe.Component;
  let name = "About";
  type props = unit;
  let render _ => <div> (ReactRe.stringToElement "About") </div>;
};

include ReactRe.CreateComponent About;

let createElement = wrapProps ();
