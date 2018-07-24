set(OP_SOURCES
  GetNumberOperation.cpp
  RandomOperation.cpp
  RollResult.cpp
  RepeatOperation.cpp
  SumOperation.cpp
  DiscardOperation.cpp
  )

set(RC_SOURCES
  RollCompare/Comparators.cpp)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(libdice_operations ${OP_SOURCES} ${RC_SOURCES})

set_property(TARGET libdice_operations PROPERTY CXX_STANDARD 14)
