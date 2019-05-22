find_package(Curses REQUIRED)


file(GLOB SRC "*.cpp")

include_directories("." ${CURSES_INCLUDE_DIR})
link_libraries(${CURSES_LIBRARIES})
add_executable(ttt ${SRC})
setupmpitarget(ttt)
