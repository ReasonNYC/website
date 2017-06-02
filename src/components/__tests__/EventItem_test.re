open Jest;

open ExpectJs;

let _ =
  describe
    "src/app.re"
    (
      fun _ =>
        test
          "renders"
          (
            fun _ => {
              let tree =
                EventItem.createElement
                  title::"Foo Title"
                  time::11234412.0
                  link::"https://google.com"
                  id::"1234"
                  description::"Hello World!"
                  children::[]
                  () |> ReactShallowRenderer.renderWithRenderer;
              expect tree |> toMatchSnapshot
            }
          )
    );
