let component = ReasonReact.statelessComponent "About";

let make _ => {
  ...component,
  render: fun () _self => <div> (ReasonReact.stringToElement "About") </div>
};
