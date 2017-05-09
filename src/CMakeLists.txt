# All header files for an executable
file(GLOB HEADERS 
  "*.h"
  "Operations/*.h")


# All source files for an executable
file(GLOB SOURCES
  "*.cpp"
  "Operations/*.cpp")

set(INCLUDE_DIRS
  Operations
  .)

include_directories(${INCLUDE_DIRS})

add_executable(DiceRoll ${HEADERS} ${SOURCES})
