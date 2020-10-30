# joint-position-tracking-test <a href="https://isocpp.org"><img src="https://img.shields.io/badge/standard-C++17-blue.svg?style=flat&logo=c%2B%2B" alt="C++ Standard" /></a>  </a><a href="./LICENSE"><img src="https://img.shields.io/badge/license-LGPL-19c2d8.svg" alt="Size" /></a>

The **joint-position-tracking-test** is a simple tool for testing the joint position tracking of a robot in a YARP environment. 

# Overview
- [:page_facing_up: Dependencies](#page_facing_up-dependencies)
- [:hammer: Build the suite](#hammer-build-the-suite)
- [:running: How to use the application](#running-how-to-use-the-application)

# :page_facing_up: Dependencies
The **joint-position-tracking-test** depends on:
- [`YARP`](https://github.com/robotology/YARP) (`YARP_dev` component)
- [`bipedal-locomotion-framework`](https://github.com/dic-iit/bipedal-locomotion-framework) (`Planners`, `ParameterHandler` and `IRobotInterface` components)

# :hammer: Build the suite
## Linux/macOS

```sh
git clone https://github.com/GiulioRomualdi/joint-position-tracking-test.git
cd joint-position-tracking-test
mkdir build && cd build
cmake ../
make
[sudo] make install
```
Notice: `sudo` is not necessary if you specify extend the `PATH`. In this case, it is necessary to add in the `.bashrc` or `.bash_profile` the following lines:
```sh
export PATH=${PATH}</path/where/you/installed>/bin
```

# :running: How to use the application
The fastest way to use the application is to run the `sh` script [`run_test.sh`](./script/run_test.sh).
The script will:
- move the robot
- store the desired and actual joint position in a txt file
- run a python script to plot the data in a file called `figure.png`

The [`jointControlOptions.ini`](./cpp/app/jointControlOptions.ini) file contains some parameters that you may modify to control a given joint:
- `max_angle_deg`: is the max angle riched by the joint (the value is in degrees)
- `min_angle_def`: is the min angle riched by the joint (the value is in degrees)
- `trajectory_duration`: is the duration of the generated trajectory (the value is in seconds)
- `robot_name`: name of the robot
- `joints_list`: list of the controlled joint (for the time being multiple joints control is not supported. Please specify only one joint)
- `remote_control_boards`: list of associated control board

This is an example of usage.
![](https://user-images.githubusercontent.com/16744101/97494667-e5576280-1966-11eb-840b-56e5120f6b29.gif)
