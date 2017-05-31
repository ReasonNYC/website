module EventItem = {
  include ReactRe.Component;
  type props = {title: string, time: float, description: string, link: string, id: string};
  let name = "EventItem";
  let handleClick _ _ => {
    Js.log "clicked!";
    None
  };
  let render {props} =>
    <li className="EventItem">
      <h3 className="EventItem-title">
        <a href=props.link target="_blank" rel="noopener">
          (ReactRe.stringToElement props.title)
        </a>
      </h3>
      <time className="EventItem-date">
        (ReactRe.stringToElement (Js.Date.toLocaleString (Js.Date.fromFloat props.time)))
      </time>
      <div
        className="EventItem-description"
        dangerouslySetInnerHTML={"__html": props.description}
      />
    </li>;
};

include ReactRe.CreateComponent EventItem;

let createElement ::title ::time ::description ::link ::id =>
  wrapProps {title, time, description, link, id};
