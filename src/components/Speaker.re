let component = ReasonReact.statelessComponent "Speaker";

let make ::name ::avatar ::company ::github ::twitter ::linkedin _children => {
  ...component,
  render: fun () _ => {
     let twitter = 
      switch (twitter) {
      | "" => ReactRe.nullElement
      | _ =>
        <TwitterIcon href=twitter />
      };
    let github = 
      switch (github) {
      | "" => ReactRe.nullElement
      | _ =>
        <GithubIcon href=github />
      };
    let linkedin = 
      switch (linkedin) {
      | "" => ReactRe.nullElement
      | _ =>
        <LinkedinIcon href=linkedin />
      };
   <div className="Speaker">
    <img
      className="Speaker__avatar"
      src=avatar
      alt=name
    />
    <div className="Speaker__name"> (ReactRe.stringToElement name) </div>
    <div className="Speaker__company">
      (ReactRe.stringToElement company)
    </div>
    <div className="Speaker__icons">
      github 
      linkedin
      twitter
    </div>
  </div>
  }
};