let component = ReasonReact.statelessComponent "App";

let make _ => {
  ...component,
  render: fun () _ => {
    let renderHomeRoute _ => <Home />;
    <RRRoute path="/" component=renderHomeRoute exact=true />
  }
};

let jsPropsToReason _ => make [||];

let comp = ReasonReact.createJsReactClass ::jsPropsToReason component;
