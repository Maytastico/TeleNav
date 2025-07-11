cmake_minimum_required(VERSION 3.8)
project(cpp_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(my_first_cpp_node src/my_first_cpp_note.cpp)
ament_target_dependencies(my_first_cpp_node rclcpp)

install(TARGETS
  my_first_cpp_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
