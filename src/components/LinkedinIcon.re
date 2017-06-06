module LinkedinIcon = {
  include ReactRe.Component;
  type props = {href: string};
  let name = "LinkedinIcon";
  let render {props} =>
    <a href=props.href target="_blank" rel="noopener">
      <svg className="Icon Icon--linkedin" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 38 38">
       <path d="M8 36.2H1.1V13H8v23.2zM4.4 10.3C1.7 10.3 0 8.3 0 6s1.8-4.2 4.5-4.2S8.9 3.7 8.9 6c0 2.3-1.7 4.3-4.5 4.3zM38 36.2h-8.2v-12c0-3.2-1.5-5.4-4.4-5.4-2.2 0-3.2 1.5-3.8 2.9-.2.5 0 1.2 0 1.9v12.6h-8.8s.1-21.8 0-23.2h8.8v3.5c0-1.6 3-3.9 7.2-3.9C34 12.6 38 16 38 23.3v12.9z"/>
      </svg>
    </a>;
};

include ReactRe.CreateComponent LinkedinIcon;

let createElement ::href => wrapProps {href: href};
