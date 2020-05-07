# @drewschrauf/bs-react-hooks-testing-library

[@testing-library/react-hooks-testing-library](https://github.com/testing-library/react-hooks-testing-library) Reason/BuckleScript bindings.

## Installation

Install as a dev dependency:

```sh
npm install --save-dev @drewschrauf/bs-react-hooks-testing-library
```

Add it to your bsconfig.json as a dev dependency.

```json
{
  ...
  "bs-dev-dependencies": [
    ...
    "@drewschrauf/bs-react-hooks-testing-library"
  ]
}
```

It's recommended to add `open ReactHooksTestingLibrary` at the top of each test file.

## API

This documentation covers the specifics of these bindings. To learn about the principles and approach behind Testing Library, refer to the [official documentation](https://testing-library.com/).

All methods from [@testing-library/react-hooks-testing-library](https://github.com/testing-library/react-hooks-testing-library) are implemented. Values that are returned from `renderHook` in the original JavaScript version have getter methods equivalents in there bindings. For example, the JavaScript method to retrieve a hooks current value is:

```javascript
const { result } = renderHook(() => React.useState(1));
console.log(result.current) // logs "1"
```

The equalivent in these bindings is the `current` method:

```reason
const result = renderHook(() => React.useState(_ => 1));
Js.log(result |> current) // logs "1"
```

Review the [interface file](https://github.com/drewschrauf/bs-testing-library/blob/mastery/packages/bs-react-hooks-testing-library/src/ReactHooksTestingLibrary.rei) for the full API. [Example tests](https://github.com/drewschrauf/bs-testing-library/blob/master/packages/bs-react-hooks-testing-library/__tests__/ReactHooksTestingLibrary_Example_test.re) are also available.