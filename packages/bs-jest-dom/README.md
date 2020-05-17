# @drewschrauf/bs-jest-dom

[@testing-library/jest-dom](https://github.com/testing-library/jest-dom) Reason/BuckleScript bindings.

Take a look at some usage [examples](https://github.com/drewschrauf/bs-testing-library/tree/master/packages/examples/__tests__).

## Installation

These bindings are intended to be used with [bs-jest](https://github.com/glennsl/bs-jest). If you don't already have it setup, follow the instructions from its repository.

Once you have bs-jest, Install these bindings as a dev dependency:

```sh
npm install --save-dev @drewschrauf/bs-jest-dom
```

Add it to your bsconfig.json as a dev dependency.

```json
{
  ...
  "bs-dev-dependencies": [
    ...
    "@drewschrauf/bs-jest-dom"
  ]
}
```

It's recommended to add `open JestDom` at the top of each test file.

## API

This documentation covers the specifics of these bindings. To learn about the principles and approach behind Testing Library, refer to the [official documentation](https://testing-library.com/).

All assertions from @testing-library/jest-dom are implemented. Generally you'd pipe a bs-jest expectation into the method like below.

```reason
expect(el) |> toBeInTheDocument
```

If the assertion can take an argument, pass positional and named optional arguments like below:

```reason
expect(el) |> toHaveClass("my-class", ~exact=false)
```

Assertions that can take multiple argument types have been split into multiple assertions. For example, `toHaveClass` and `toHaveClasses` take a `string` and `list(string)` respectively. Refer to the [interface file](https://github.com/drewschrauf/bs-testing-library/blob/master/packages/bs-jest-dom/src/JestDom.rei) for a full list of assertions.
