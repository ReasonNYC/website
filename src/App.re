open ReactRouter;

open Event;

module App = {
  include ReactRe.Component.JsProps;
  let name = "App";
  type props = {
    /* An array of Meetup.com events */
    events: array event
  };
  let render {props} =>
    <div>
      <NavLink _to="/about"> (ReactRe.stringToElement "About") </NavLink>
      <NavLink _to="/"> (ReactRe.stringToElement "Home") </NavLink>
      <Route path="/" component=(fun _ => <Home events=props.events />) exact=true />
      <Route path="/about" component=(fun _ => <About />) exact=true />
    </div>;
  /* Tell Reason-React how to transform JS props into ReasonML */
  type jsProps = Js.t {. events : array event};
  let jsPropsToReasonProps = Some (fun jsProps => {events: jsProps##events});
};

include ReactRe.CreateComponent App;

let createElement ::events => wrapProps {events: events};
