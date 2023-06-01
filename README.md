# OpenAnimationReplacer-ExamplePlugin

This is a SKSE64 plugin example utilizing Open Animation Replacer's API to add a new custom condition.

### Requirements
* [XMake](https://xmake.io) [2.7.8+]
* C++20 Compiler (MSVC, Clang?)

## Getting Started
```bat
git clone https://github.com/ersh1/OpenAnimationReplacer-ExamplePlugin
cd OpenAnimationReplacer-ExamplePlugin
```

### Build
To build the project, run the following command:
```bat
xmake build
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory** with the build output.*

### Build Output (Optional)
If you want to redirect the build output, set one of or both of the following environment variables:

- Path(s) to a Skyrim install folder: `SKYRIM_PATH`

- Path(s) to a Mod Manager mods folder: `SKYRIM_MODS_PATH`

> ***Note:*** *Both variables support semicolon (`;`) seperated paths for multiple game installs or `mods` folders.*

### Project Generation (Optional)
If you want to generate a Visual Studio project, run the following command:
```bat
xmake project -k vsxmake
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system.*

### Upgrading Packages (Optional)
If you want to upgrade the project's dependencies, run the following commands:
```bat
xmake repo --update
xmake require --upgrade
```
