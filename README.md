# C++23 Project with Xmake, GTest, and CI/CD

This repository provides a simple setup for a C++23 project using Xmake as the build system, GTest for unit testing, and CI/CD workflows for both Ubuntu and Windows (x64 and x86).

**Note:** Please be aware that `import std;` currently only works for the Windows MSVC compiler and not for GCC. Modules are still not fully supported in any compiler. For example, `std::print` (`import <print>`) doesn't work in GCC-13.

## Enabling GitHub Workflow to Automatically Create Releases
To allow GitHub Actions to create releases automatically, you need to grant the necessary permissions. Follow these steps:

Go to your GitHub project's `Settings` page.
Navigate to the `Actions` tab.
Under the `Workflow permissions` section, select `Read and write permissions`.
If you don't enable these permissions, the `Release` step of the workflows will fail, and the releases won't be created automatically.

## Project Structure

The project structure is as follows:
```
.
├── .github
│   └── workflows
│       ├── greetings.yml
│       ├── linux.yml
│       └── windows.yml
├── src
│   ├── hello.cppm
│   └── main.cppm
├── tests
│   ├── test_gmock.cpp
│   └── test_gtest.cpp
└── xmake.lua
```
- `.github/workflows/`: Directory containing the CI/CD workflow files.
  - `greetings.yml`: Workflow file for greeting users on their first issue or pull request.
  - `linux.yml`: Workflow file for building and releasing the project on Linux (Ubuntu).
  - `windows.yml`: Workflow file for building and releasing the project on Windows.
- `src/`: Directory containing the source files of the project.
- `tests/`: Directory containing the test files using GTest and GMock.
- `xmake.lua`: The Xmake configuration file.

## Prerequisites

Before building and running the project, ensure that you have the following dependencies installed:

- Xmake: [Installation Guide](https://xmake.io/#/guide/installation)
- C++23 compiler (e.g., GCC, Clang, or MSVC). Currently I could not get it working with Clang and GCC does not have as good module support as MSVC.

## Building the Project

To build the project, run the following command in the project root directory:

```xmake```

This command will compile the source files and generate the executable.

You can also use `xmake config` (or `xmake f`) to configure the project. For example, to set the project to compile as 32-bit, use the following command:

```xmake f -a x86```

This will configure the project to compile as 32-bit the next time you run `xmake` or `xmake build`.

To clean the project and remove the build files, use the following command:

```xmake clean```

## Running the Tests

To run the tests, use the following command:
```xmake test```

This command will execute the test files and display the test results.

## CI/CD Workflows

The repository includes several CI/CD workflow files located in the `.github/workflows/` directory:

1. `linux_cd.yml`: Builds the project on Linux (Ubuntu) for x86_64 and x86 architectures, creates a release tag, generates a changelog, and uploads the executable as release assets.

2. `windows_cd.yml`: Builds the project on Windows for x64 and x86 architectures, creates a release tag, generates a changelog, and uploads the executable as release assets.

3. `greetings.yml`: Greets users on their first issue or pull request.

These workflows automate the build, testing, and release processes for the project.

## Customization

This repository serves as a template and can be customized to suit your project's specific needs. Feel free to modify the project structure, add or remove files, and adjust the Xmake configuration and CI/CD workflows according to your requirements.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [Unlicense license](LICENSE).
