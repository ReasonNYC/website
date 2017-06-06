module Speaker = {
  include ReactRe.Component;
  type props = {
    name: string,
    avatar: string,
    company: string,
    github: string,
    twitter: string,
    linkedin: string
  };
  let name = "Speaker";
  let render {props} => {
    let twitter = 
      switch (props.twitter) {
      | "" => ReactRe.nullElement
      | _ =>
        <TwitterIcon href=props.twitter />
      };
    let github = 
      switch (props.github) {
      | "" => ReactRe.nullElement
      | _ =>
        <GithubIcon href=props.github />
      };
    let linkedin = 
      switch (props.linkedin) {
      | "" => ReactRe.nullElement
      | _ =>
        <LinkedinIcon href=props.linkedin />
      };
   <div className="Speaker">
    <img
      className="Speaker__avatar"
      src=props.avatar
      alt=props.name
    />
    <div className="Speaker__name"> (ReactRe.stringToElement props.name) </div>
    <div className="Speaker__company">
      (ReactRe.stringToElement props.company)
    </div>
    <div className="Speaker__icons">
      github 
      linkedin
      twitter
    </div>
  </div>
  };
};

include ReactRe.CreateComponent Speaker;

let createElement ::name ::avatar ::company ::github ::twitter ::linkedin => wrapProps {avatar, name, company, github, twitter, linkedin};
