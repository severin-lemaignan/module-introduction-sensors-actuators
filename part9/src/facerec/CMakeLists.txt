cmake_minimum_required(VERSION 2.8.3)
project(facerec)

find_package(catkin REQUIRED COMPONENTS
  rospy
)

catkin_python_setup()
catkin_package()

install(PROGRAMS
   scripts/reco
   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

