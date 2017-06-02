external browserRouter : ReactRe.reactClass = "BrowserRouter" [@@bs.module "react-router-dom"];

external navLink : ReactRe.reactClass = "NavLink" [@@bs.module "react-router-dom"];

external route : ReactRe.reactClass = "Route" [@@bs.module "react-router-dom"];

type rrfn = Js.t {. _match : Js.t {. url : string}};

module Route = {
  let createElement exact::(exact: bool) path::(path: string) component::(component: 'a) =>
    ReactRe.wrapPropsShamelessly
      route {"exact": Js.Boolean.to_js_boolean exact, "path": path, "component": component};
};

module NavLink = {
  let createElement _to::(_to: string) => ReactRe.wrapPropsShamelessly navLink {"to": _to};
};

module BrowserRouter = {
  let createElement = ReactRe.wrapPropsShamelessly browserRouter (Js.Obj.empty ());
};
