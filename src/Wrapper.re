/**
 * Not Used, just for an example.
 * This is Stateless Functional Component equivalent that is just for CSS.
 */
module Wrapper = {
  include ReactRe.Component;
  let name = "Wrapper";
  type props = { 
    width: string,
    children: list ReactRe.reactElement 
  };
  let render {props: { width, children }} => {
    <div className=("Wrapper Wrapper--" ^ width)>
      (ReactRe.listToElement children)
    </div>;
  };
};

include ReactRe.CreateComponent Wrapper;

let createElement ::width ::children => wrapProps { width: width, children: children } ::children;