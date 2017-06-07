set(TEST_SOURCES
  main.cpp
  GetNumberOperationTest.cpp
  RandomOperationTest.cpp
  )

add_executable(dice_test ${TEST_SOURCES})

target_link_libraries(dice_test
  gtest
  libdice_operations)

