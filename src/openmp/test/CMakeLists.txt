FILE(GLOB SRC "./*.cpp")

SET(CUSTOM_COMPILE_FLAGS "-Wall -pedantic")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CUSTOM_COMPILE_FLAGS}")

add_executable(main ${SRC})
