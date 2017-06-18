let component = ReasonReact.statelessComponent "App";

let make _ => {
  ...component,
  render: fun () _ => {
    let renderHomeRoute _ => <Home />;
    <RRRoute path="/" component=renderHomeRoute exact=true />
  }
};

let comp = ReasonReact.wrapReasonForJs ::component (fun _ => make [||]);
