# ESP32 Boilerplate

A bare-bones boilerplate for ESP32 development. Initially generated using Espressif IoT Development Framework (ESP-IDF) `create-project` on an M1 Mac.

## Prerequisits

This project assumes the installation and configuration of [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html).

Additionaly, this boilerplate was created using [VSCode](https://code.visualstudio.com/) and the [Espressif IDF](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension) and [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) extensions.

## Gettings Started

Clone this project and flash it to your device:
```
git clone https://github.com/jesseflorig/esp32-boilerplate
cd esp32-boilerplate
idf.py -p [PORT] flash
```

This will clone the repo and flash the program to the device located at `PORT`. For help finding which `PORT` your device is on, refer to the [ESP-IDF docs](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html).

## Project Layout

Mostly a re-hashing of ESP-IDF's [Example Project documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#example-project).

 - `README.md` - this file
 - `.gitignore` - tells git which files/directories to ignore for source control
 - `CMakeLists.txt` - project wide configuration for CMake
 - `sdkconfig` - Auto-generated config file from `idf.py menuconfig`
 - `workspace.code-workspace` - VSCode workspace file (seems to help C/C++ intellisense)
 - `main/` directory - root component for the project
    - `CMakeLists.txt` - root component build configuration for CMake
    - `esp32-boilerplate.c` - main project source (must match `SRCS` filename in `main/CMakeLists.txt`)
 - `components/` directory - holds reusable code and third party components from outside ESP-IDF
    - `[COMPONENT]/` directory - would be named after whatever third party component it contains
        - `CMakeLists.txt` - component build configuration for CMake
        - `Kconfig` - component configuration set via `idf.py menuconfig`
        - `[SRC].c` - component code
 - `build/` directory - automatically generated by `idf.py build` (excluded from source control)
 - `.vscode/` directory - IDE and extension configurations

 ## Adding Components

 From the project root:
 ```
idf.py -C components create-component my_component
 ```

 This will create a new `my_component/` directory in the `components/` directory