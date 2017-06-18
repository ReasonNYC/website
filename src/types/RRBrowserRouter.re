external browserRouter : ReactRe.reactClass = "BrowserRouter" [@@bs.module "react-router-dom"];

let make _ =>
  ReasonReact.wrapJsForReason reactClass::browserRouter props::(Js.Obj.empty ());
