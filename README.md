# Custom Clang Tidy plugin

## Viewing Clang AST

To view the AST for the constructors of the class `ExampleBad` run

`clang-check --ast-dump --ast-dump-filter="ExampleBad::ExampleBad" example/example.cpp`


## Compiling

`cd build`

`cmake ..`

`make`

## Linking

To link our shared library with clang-tidy we use the `--load` flag.

For example:

`clang-tidy --list-checks --checks=* --load=lib/libMoveConstructorNoexcept.dylib`

If it is linked correctly there should be a check listed named "move-constructor-noexcept."


