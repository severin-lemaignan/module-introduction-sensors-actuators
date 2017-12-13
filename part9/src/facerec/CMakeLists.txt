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

install(DIRECTORY ${CMAKE_SOURCE_DIR}/share/dataset
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
