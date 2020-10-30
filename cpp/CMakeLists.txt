# This software may be modified and distributed under the terms of the
# GNU Lesser General Public License v2.1 or any later version.
# Authors: Giulio Romualdi

# set target name
set(EXE_TARGET_NAME JointPositionTrackingTest)

# set cpp files
set(${EXE_TARGET_NAME}_SRC
  src/main.cpp
  src/module.cpp)

# set hpp files
set(${EXE_TARGET_NAME}_HDR
  include/module.h)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add an executable to the project using the specified source files.
add_executable(${EXE_TARGET_NAME} ${${EXE_TARGET_NAME}_SRC} ${${EXE_TARGET_NAME}_HDR})

target_link_libraries(${EXE_TARGET_NAME}
  YARP::YARP_dev
  BipedalLocomotion::Planners
  BipedalLocomotion::ParametersHandlerYarpImplementation
  BipedalLocomotion::RobotInterfaceYarpImplementation)

install(TARGETS ${EXE_TARGET_NAME} DESTINATION bin)
