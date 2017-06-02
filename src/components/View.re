open Event; 
/* need event type*/

module View = {
  include ReactRe.Component;
  type props = {view: unit => ReactRe.reactElement, events: array event};
  let name = "View";
  let render {props} => {
    Js.log props;
    <div className="pure-g">
      (props.view ())
    </div>;
  };
};

include ReactRe.CreateComponent View;

let createElement ::view ::events => wrapProps {view: view, events: events };