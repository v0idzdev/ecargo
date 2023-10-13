cmake_minimum_required(VERSION 3.15...3.25)
project(
  ecargo
  VERSION 0.1.0
  DESCRIPTION "A minimal file transfer application."
  LANGUAGES C
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON) # check if includes not working
  include(CTest)
endif()

add_subdirectory(src)
add_subdirectory(apps)

if (BUILD_TESTING)
  add_subdirectory(tests)
endif()