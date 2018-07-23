set(SOURCES
  GetNumberOperation.cpp
  RandomOperation.cpp
  RollResult.cpp
  RepeatOperation.cpp
  SumOperation.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(libdice_operations ${SOURCES})

set_property(TARGET libdice_operations PROPERTY CXX_STANDARD 14)
