# @drewschrauf/bs-dom-testing-library

[@testing-library/dom-testing-library](https://github.com/testing-library/dom-testing-library) Reason/BuckleScript bindings.

Take a look at some usage [examples](https://github.com/drewschrauf/bs-testing-library/tree/master/packages/examples/__tests__).

## Installation

**If you're using reason-react, don't install this! Follow the installation instructions for @drewschrauf/bs-react-testing-library instead.**

Install as a dev dependency:

```sh
npm install --save-dev @drewschrauf/bs-dom-testing-library
```

Add it to your bsconfig.json as a dev dependency.

```json
{
  ...
  "bs-dev-dependencies": [
    ...
    "@drewschrauf/bs-dom-testing-library"
  ]
}
```

It's recommended to add `open DomTestingLibrary` at the top of each test file.

## API

This documentation covers the specifics of these bindings. To learn about the principles and approach behind Testing Library, refer to the [official documentation](https://testing-library.com/).

### Queries

There are [48 queries](https://testing-library.com/docs/dom-testing-library/api-queries) provided by @testing-library/dom-testing-library. They are a product of:

- `getBy`, `getAllBy`, `queryBy`, `queryAllBy`, `findBy`, `findAllBy`; and
- `ByLabelText`, `ByPlaceholderText`, `ByText`, `ByAltText`, `ByTitle`, `ByDisplayValue`, `ByRole`, `ByTestId`

This project extends these by a third dimension for the matcher:

- String (no suffix)
- Regex (`Re` suffix)
- Function (`Fn` suffix)

This makes a total of 144 query methods that can be built from these parts, for example:

- `getByText`
- `queryAllByTitleRe`
- `findByRoleFn`

Additional options are passed as optional named arguments, for example:

```reason
getByText("Text", ~exact=false)
```

Refer to the [Testing Library documentation](https://testing-library.com/docs/dom-testing-library/api-queries) for a full list of options supported by each query.

### FireEvent

Events can be fired using methods in the `FireEvent` module. Generally you'd pipe an element into the method like below.

```reason
element |> FireEvent.click
```

If the event requires a payload (like `change`), pass the `eventInit` optional named parameter.

```reason
element |> FireEvent.change({ "target": { "value": "new value" } })
```

Be sure to include the double quotes in the payload object! This ensures reason interprets it as a value of type `Js.t` instead of a record.

### Utilities

At this point, the following utilities are implemented:

- `waitFor`
- `waitForElementToBeRemoved`
- `debug`
- `prettyDOM`
- `screen`

Pull requests are appreciated for the rest of the suite.
