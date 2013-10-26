project(cmakeplayground)
add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=1)

cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/lib)

include_directories(./src/Interfaces)
include_directories(./src/Main)
aux_source_directory(./src/Main SRC_LIST)

include_directories(./src/Navigation)
aux_source_directory(./src/Navigation SRC_LIST)

include_directories(./src/Help)
aux_source_directory(./src/Help SRC_LIST)

include_directories(./test/Mocks )
aux_source_directory(./test/Mocks SRC_LIST)

aux_source_directory(./test SRC_LIST)


add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} gmock gmock_main)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
