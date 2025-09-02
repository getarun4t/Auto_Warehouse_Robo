cmake_minimum_required(VERSION 3.8)
project(warehouse_robot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(warehouse_publisher src/warehouse_publisher_node.cpp)
add_executable(warehouse_subscriber src/warehouse_subscriber_node.cpp)

ament_target_dependencies(warehouse_publisher rclcpp example_interfaces)
ament_target_dependencies(warehouse_subscriber rclcpp example_interfaces)

install(TARGETS
  warehouse_publisher
  warehouse_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
