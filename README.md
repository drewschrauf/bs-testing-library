# @testing-library BuckleScript bindings

This project provide BuckleScript bindings for the [@testing-library](https://testing-library.com/) ecosystem.

- [@drewschrauf/bs-dom-testing-library](./packages/bs-dom-testing-library) - BuckleScript bindings for [@testing-library/dom](https://github.com/testing-library/dom-testing-library).
- [@drewschrauf/bs-react-testing-library](./packages/bs-react-testing-library) - BuckleScript bindings for [@testing-library/react](https://github.com/testing-library/react-testing-library)
- [@drewschrauf/bs-jest-dom](./packages/bs-jest-dom) - BuckleScript bindings for [@testing-library/jest-dom](https://github.com/testing-library/jest-dom)

## Motivation

This is not the only set of bindings available to use Testing Library with BuckleScript. Projects exist for [bs-dom-testing-library](https://github.com/wyze/bs-dom-testing-library), [bs-react-testing-library](https://github.com/wyze/bs-react-testing-library) and [bs-jest-dom](https://github.com/wyze/bs-jest-dom) which are linked to from the Testing Library documentation.

These projects provide a more "literal" mapping to the underlying framework. However, the dynamic nature of JavaScript can lead to awkward ergonomics when attempting to map to BuckleScript.

This project attempts to reimagine the ecosystem to feel more at home in the Reason world. See the individual libraries in this project for the specifics.

## Acknowledgments

[@wyze](https://github.com/wyze) - The original bindings were a great reference for marshalling techniques between the Reason and JavaScript worlds.