let component = ReasonReact.statelessComponent "About";

let make _ => {
  ...component, /* spread the template's other defaults into here  */
  render: fun () _self => <div> (ReasonReact.stringToElement "About") </div>
};
