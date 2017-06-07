external browserRouter : ReactRe.reactClass = "BrowserRouter" [@@bs.module "react-router-dom"];

let make _ =>
  ReasonReact.wrapJsComponentForReason reactClass::browserRouter props::(Js.Obj.empty ());
