add_subdirectory(Operations)

file(GLOB OPERATION_SOURCES "Operations/*.cpp")

add_executable(AdvancedDiceRoll.out main.cpp ${OPERATION_SOURCES})
