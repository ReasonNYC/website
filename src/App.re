open ReactRouter;
open Event;

let createView view events _ => <View view events />;

type routeConfig = { path: string, view: unit => ReactRe.reactElement, events: array event };

module App = {
  include ReactRe.Component.JsProps;
  let name = "App";
  
  type props = {
    /* An array of Meetup.com events */
    events: array event
  };

  let render {props} => {
    let routes = [
      { path: "/", view: fun _ => <HomeNew />, events: props.events  },
      { path: "/about", view: fun _ => <About />, events: props.events },
    ];
    <div> (
          ReactRe.listToElement (
            List.map
              (
                fun a =>
                  <Route
                    key=a.path
                    path=a.path
                    component=(createView a.view props.events)
                    exact=true
                  />
              )
              routes
          )
        ) </div>;
  };

  /* Tell Reason-React how to transform JS props into ReasonML */
  type jsProps = Js.t {. events : array event};
  let jsPropsToReasonProps = Some (fun jsProps => {events: jsProps##events});
};

include ReactRe.CreateComponent App;

let createElement ::events => wrapProps {events: events};
