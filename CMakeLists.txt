cmake_minimum_required(VERSION 3.5.1)
project("advanced_dice_roll")

set(CMAKE_CXX_FLAGS "-std=c++11 -W -Wall -Wextra -Werror")

set(INCLUDE_DIRS include/gsl src src/Operations)
file(GLOB SOURCES "src/*.cpp" "src/Operations/*.cpp")


include_directories(${INCLUDE_DIRS})

add_executable(DiceRoll ${SOURCES})
