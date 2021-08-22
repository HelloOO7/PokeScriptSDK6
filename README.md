# PokéScript Generation VI Software Development Kit

This repository contains headers, definitions and utilities that can be used in conjunction with the PokéScript compiler to produce efficient and powerful field event scripts for Pokémon X/Y and OR/AS. The project can be used out-of-the-box as a PokéScript IDE include library and does not rely on any external dependencies. All code is intended to be compiled and executed on the Pawn32/AMX_CTR platform and will not have much of a purpose on other PokéScript targets.

## Building

SDK6 is a PokéScript source library without any standalone executable code, which means it can not be built as program. Sources will get built and included automatically as they are imported into a parent project's runnable source files.

## Usage

Include the SDK root in your project, either using the IDE, or with:

`-I <path/to/SDK>/src` or `--include <path/to/SDK>/src`

Then import classes using their defined `package` and names.

To specify the target game version, define the following constants:

-	`SANGO` for Pokémon OR/AS
-	`XY` for Pokémon X/Y

You can pass compiler definitions either with the `#define` preprocessor keyword, or with the `-D` or `--define` compiler argument, or through the IDE.

## Contributing

Thanks for your interest in contributing to the PokéScript SDKs!

If you have researched a new native function, written a handy utility or extension, or simply feel like some part of the classes needs refactoring or clarification, feel free to submit an issue or a pull request.