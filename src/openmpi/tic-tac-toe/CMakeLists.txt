find_package(Curses REQUIRED)

file(GLOB SRC "*.cpp")

#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

include_directories("." ${CURSES_INCLUDE_DIR})
link_libraries(${CURSES_LIBRARIES})
add_executable(ttt ${SRC})
setupmpitarget(ttt)
