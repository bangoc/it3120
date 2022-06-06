cmake_minimum_required(VERSION 3.0)
project(MVCDemo-guess-number)
find_package(wxWidgets 3.0 REQUIRED)

include(${wxWidgets_USE_FILE})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
  add_definitions(-DDEBUG)
endif()

add_executable(guess_number main.cpp game_model.cpp game_view.cpp)
target_link_libraries(guess_number ${wxWidgets_LIBRARIES})