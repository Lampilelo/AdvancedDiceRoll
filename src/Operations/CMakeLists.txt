set(SOURCES
  GetNumberOperation.cpp
  RandomOperation.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(libdice_operations ${SOURCES})
