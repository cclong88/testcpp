cmake_minimum_required(VERSION 3.0)

if (POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif ()
if (POLICY CMP0057)
    cmake_policy(SET CMP0057 NEW)
endif ()

set(PACKAGE_NAME "ccl-cpp")
set(PACKAGE_VERSION "0.0.1-dev")
set(PACKAGE_STRING    "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_TARNAME   "${PACKAGE_NAME}-${PACKAGE_VERSION}")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
project(${PACKAGE_NAME} CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options("-g" "-Wall" "-stdlib=libc++")

enable_testing()

set(TOP_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

set(DEPENDENT_LIBS
    c++
    c++abi
    pthread)

foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_executable(${_test_name} ${_test_file})
    target_link_libraries(${_test_name} ${DEPENDENT_LIBS})
    add_test(${_test_name} ${_test_name})
    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
endforeach()
