type event =
  Js.t {
    .
    /* Unique identifier*/
    id : string,
    /* Name of the Event */
    title : string,
    /* Description */
    description : string,
    /* Start time */
    time : float,
    /* Url to Meetup.com event */
    link : string
  };