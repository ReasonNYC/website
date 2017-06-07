let component = ReasonReact.statelessComponent "App";

let make _ => {
  ...component, /* spread the template's other defaults into here  */
  render: fun () _ => <div> <Home /> </div>
};

let jsPropsToReason _ => make [||];

let comp = ReasonReact.createJsReactClass ::jsPropsToReason component;
