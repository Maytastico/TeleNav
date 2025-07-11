cmake_minimum_required(VERSION 3.8)
project(my_robot_description)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

install(
  DIRECTORY urdf urdf_course launch meshes rviz
  DESTINATION share/${PROJECT_NAME}/
)

find_package(xacro REQUIRED)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/urdf_cource/robot.urdf
  COMMAND xacro ${CMAKE_CURRENT_SOURCE_DIR}/urdf_cource/robot.urdf.xacro -o ${CMAKE_CURRENT_SOURCE_DIR}/urdf_cource/robot.urdf
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/urdf_cource/robot.urdf.xacro
)

add_custom_target(generate_urdf ALL
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/urdf_cource/robot.urdf
)

install(
  FILES ${CMAKE_CURRENT_SOURCE_DIR}/urdf_cource/robot.urdf
  DESTINATION share/${PROJECT_NAME}/urdf_cource
)
ament_package()
