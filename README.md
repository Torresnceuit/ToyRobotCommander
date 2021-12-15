# ToyRobotCommander

## Description

* The application is a simulation of a toy robot moving on a square tabletop, of dimensions 5 units x 5 units.

* There are no other obstructions on the table surface.

* The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

Create an application that can read in commands of the following form:
```
PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT
```

* `PLACE` will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.

* The origin (0,0) can be considered to be the SOUTH WEST most corner.

* The first valid command to the robot is a `PLACE` command, after that, any sequence of commands may be issued, in any order, including another `PLACE` command. The application should discard all commands in the sequence until a valid `PLACE` command has been executed

* `MOVE` will move the toy robot one unit forward in the direction it is currently facing.

* `LEFT` and `RIGHT` will rotate the robot 90 degrees in the specified direction without changing the position of the robot.

* `REPORT` will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.

* A robot that is not on the table can choose to ignore the `MOVE`, `LEFT`, `RIGHT` and `REPORT` commands.

* Input can be from a file, or from standard input, as the developer chooses.

* Provide test data to exercise the application.

### Constraints

* The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.

* Any move that would cause the robot to fall must be ignored.

### Example Input and Output:

#### Example a

    PLACE 0,0,NORTH
    MOVE
    REPORT

Expected output:

    0,1,NORTH

#### Example b

    PLACE 0,0,NORTH
    LEFT
    REPORT

Expected output:

    0,0,WEST

#### Example c

    PLACE 1,2,EAST
    MOVE
    MOVE
    LEFT
    MOVE
    REPORT

Expected output

    3,3,NORTH
    
 #### Example d

    PLACE 0,0,NORTH RIGHT RIGHT LEFT MOVE REPORT

Expected output

    1,0,EAST
    
## Setup

### Install CMake (2.8 or higher)
Running ```brew install cmake``` on Mac OSX or following the ```CMake``` instruction to install for other platforms: https://cmake.org/install/.
### Install Google Test
On Mac OSX, use the command ```brew install googletest``` to install. For other platforms, it can be built from a source code by following these steps:
```
git clone https://github.com/google/googletest
cd googletest
mkdir build
cd build
cmake -DCMAKE_CXX_FLAGS=-std=c++17 ..

cp -a ../googletest/include/* /usr/local/include
cp -a ../googlemock/include/* /usr/local/include
find . -name "*.a" -exec cp -a {} /usr/local/lib \;
```
DONE.

## Compile Project
The application is compiled by C++17 with two parts: main ```ToyRobot``` application and ```CommanderTests``` for UnitTest.
```
git clone git@github.com:Torresnceuit/ToyRobotCommander.git
cd ToyRobotCommander
mkdir build
cmake ..
make
```

### Run CommanderTests
```
cd build/Commander/tests
./CommanderTests
```
![TestResult](https://github.com/Torresnceuit/ToyRobotCommander/blob/master/Commander/tests/output/TestResult.png)

### Run Executable Commander
In build folder, execute the application
```./ToyRobot```
Enjoy!!!




