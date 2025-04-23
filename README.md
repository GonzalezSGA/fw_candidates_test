# Technical Test for Embedded Software Engineer #

### Dependencies ###

* [Cmake](https://cmake.org/) At least version 3.16.
* Any GNU C compiler equal or above 4.8.0 should work. Recommended gcc 9.4.0, included with WSL.

### Set up

* Clone the code or unzip it to a source_dir
* Configure the project:

```
cd source_dir
mkdir build
cd build
cmake ..
```

* Build the project:

```
make
```

### Unit tests

The repository includes the infrastructure to run unit tests with [Ceedling and Unity](https://www.throwtheswitch.org/ceedling). It requires [version 1.0.1b of the docker image](https://github.com/ThrowTheSwitch/MadScienceLabDocker/releases/tag/1.0.1b) that can be obtained by:

```
docker pull throwtheswitch/madsciencelab:1.0.1b
docker run -it --rm -v <local project path>:/home/dev/project throwtheswitch/madsciencelab:1.0.1b
```

Then, once you get the ceedling prompt

```
ceedling test:all

🚧 Loaded project configuration from working directory.
 > Using: /workspaces/project.yml
 > Working directory: /workspaces

Ceedling set up completed in 65 milliseconds

👟 Preparing Build Paths...

👟 Collecting Test Context
--------------------------
Parsing test_autoid.c for build directive macros, #includes, and test case names...

👟 Ingesting Test Configurations
--------------------------------
Collecting search paths, flags, and defines test_autoid.c...

👟 Determining Files to be Generated...

👟 Mocking
----------
Generating mock for test_autoid::rs485.h...
Generating mock for test_autoid::protocol.h...

👟 Test Runners
---------------
Generating runner for test_autoid.c...

👟 Determining Artifacts to Be Built...

👟 Building Objects
-------------------
Compiling test_autoid.c...
Compiling test_autoid::autoid.c...
Compiling test_autoid::mock_rs485.c...
Compiling test_autoid::mock_protocol.c...
Compiling test_autoid::test_autoid_runner.c...
Compiling test_autoid::unity.c...
Compiling test_autoid::cmock.c...

👟 Building Test Executables
----------------------------
Linking test_autoid.out...

👟 Executing
------------
Running test_autoid.out...

[==========]
[ TEST     ]
[==========] Running 1 tests from 1 test cases.
[----------] Global test environment set-up.
[----------] 1 tests from test/test_autoid.c
[ RUN      ] test/test_autoid.c.test_auto_identify_terminals__dummy
[       OK ] test/test_autoid.c.test_auto_identify_terminals__dummy (0 ms)
[----------] 1 tests from test/test_autoid.c (1 ms total)

[----------] Global test environment tear-down.
[==========] 1 tests from 1 test cases ran.
[  PASSED  ] 1 tests.
[  FAILED  ] 0 tests.

 0 FAILED TESTS

Running Test Suite Reports
--------------------------
Generating artifact build/test/artifacts/test/junit_tests_report.xml...


Ceedling operations completed in 434 milliseconds
```

The project also includes a [devcontainer file to be used from VsCode](https://code.visualstudio.com/docs/devcontainers/containers).