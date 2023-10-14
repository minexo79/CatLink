# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project("catlink_test")

# create test01 executeable
add_executable(catlink_test01)
target_sources(catlink_test01 PRIVATE "test/test01.c")

# add & link src lib
target_include_directories(catlink_test01 PRIVATE "src/")
add_subdirectory("src/")
target_link_libraries(catlink_test01 PRIVATE src)