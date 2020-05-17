open Jest;
open Expect;
open ReactTestingLibrary;
open JestDom;

module ExampleForm = {
  [@react.component]
  let make = () => {
    let (name, setName) = React.useState(_ => "");
    let (favouriteLanguage, setFavouriteLanguage) = React.useState(_ => "");
    let (subscribe, setSubscribe) = React.useState(_ => false);

    <form role="form">
      <div>
        <label htmlFor="name"> "Name"->React.string </label>
        <input
          id="name"
          name="name"
          required=true
          value=name
          onChange={e => {
            let value = ReactEvent.Form.target(e)##value;
            setName(_ => value);
          }}
        />
      </div>
      <div>
        <label htmlFor="favourite-language">
          "Favourite language"->React.string
        </label>
        <select
          id="favourite-language"
          name="favouriteLanguage"
          value=favouriteLanguage
          onChange={e => {
            let value = ReactEvent.Form.target(e)##value;
            setFavouriteLanguage(_ => value);
          }}>
          <option value="re"> "Reason"->React.string </option>
          <option value="ts"> "TypeScript"->React.string </option>
          <option value="js"> "JavaScript"->React.string </option>
        </select>
      </div>
      <div>
        <label htmlFor="subscribe"> "Subscribe?"->React.string </label>
        <input
          type_="checkbox"
          id="subscribe"
          name="subscribe"
          checked=subscribe
          onChange={e => {
            let value = ReactEvent.Form.target(e)##value;
            setSubscribe(_ => value);
          }}
        />
      </div>
    </form>;
  };
};

test("change input", () => {
  let root = render(<ExampleForm />);

  let input = root |> getByLabelText("Name");
  input |> FireEvent.change(~eventInit={
                              "target": {
                                "value": "Drew",
                              },
                            });

  expect(input) |> toHaveValue("Drew");
});

test("change select", () => {
  let root = render(<ExampleForm />);

  let select = root |> getByLabelText("Favourite language");
  select |> FireEvent.change(~eventInit={
                               "target": {
                                 "value": "re",
                               },
                             });

  expect(select) |> toHaveDisplayValue("Reason");
});

test("change checkbox", () => {
  let root = render(<ExampleForm />);

  let checkbox = root |> getByLabelText("Subscribe?");
  checkbox |> FireEvent.click;

  expect(checkbox) |> toBeChecked;
});

test("form values", () => {
  let root = render(<ExampleForm />);

  let input = root |> getByLabelText("Name");
  input |> FireEvent.change(~eventInit={
                              "target": {
                                "value": "Drew",
                              },
                            });

  let select = root |> getByLabelText("Favourite language");
  select |> FireEvent.change(~eventInit={
                               "target": {
                                 "value": "re",
                               },
                             });

  let subscribe = root |> getByLabelText("Subscribe?");
  subscribe |> FireEvent.click;

  root
  |> getByRole("form")
  |> expect
  |> toHaveFormValues({
       "name": "Drew",
       "favouriteLanguage": "re",
       "subscribe": true,
     });
});

/* the name input is required so if there's no name, it's invalid */
test("invalid form", () =>
  render(<ExampleForm />) |> getByRole("form") |> expect |> toBeInvalid
);

test("valid form", () => {
  let root = render(<ExampleForm />);

  root
  |> getByLabelText("Name")
  |> FireEvent.change(~eventInit={
                        "target": {
                          "value": "Drew",
                        },
                      });

  root |> getByRole("form") |> expect |> toBeValid;
});
