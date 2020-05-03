# @drewschrauf/bs-react-testing-library

[@testing-library/react-testing-library](https://github.com/testing-library/react-testing-library) Reason/BuckleScript bindings.

Take a look at some usage [examples](https://github.com/drewschrauf/bs-testing-library/tree/master/packages/bs-react-testing-library/__tests__/examples).

## Installation

Install as a dev dependency:

```sh
npm install --save-dev @drewschrauf/bs-react-testing-library
```

Add it to your bsconfig.json as a dev dependency.

```json
{
  ...
  "bs-dev-dependencies": [
    ...
    "@drewschrauf/bs-react-testing-library"
  ]
}
```

It's recommended to add `open ReactTestingLibrary` at the top of each test file.

## API

This documentation covers the specifics of these bindings. To learn about the principles and approach behind Testing Library, refer to the [official documentation](https://testing-library.com/).

This is an extremely thin wrapper around [@drewschrauf/bs-dom-testing-library](https://github.com/drewschrauf/bs-testing-library/tree/master/packages/bs-dom-testing-library). Refer to the documentatation of that package for an explanation on queries and events.

### Render

The primary additional method provided by this package is `render`. It renders a React component and returns the container element. This is different from the JavaScript version which prebinds all of the queries and additional helper methods to the render result. This isn't necessary in the Reason world as the piping syntax is must more natural.

The resulting element can be piped directory into a query like below:

```reason
render(<MyComponent />) |> getByText("Some text")
```

May more [usage examples](https://github.com/drewschrauf/bs-testing-library/tree/master/packages/bs-react-testing-library/__tests__/examples) can be found in this repository.

Other methods that are returned when rendering using @testing-library/react (such as `unmount` and `rerender`) are not yet implemented. Pull requests are appreciated for the rest of the suite.
