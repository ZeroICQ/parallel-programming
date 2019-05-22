find_package(Curses REQUIRED)

include_directories("." ${CURSES_INCLUDE_DIR})
link_libraries(${CURSES_LIBRARIES})
add_executable(ttt_server ttt_server.cpp GameBoard.cpp)
setupmpitarget(ttt_server)

add_executable(ttt_client ttt_client.cpp GameBoard.cpp)
setupmpitarget(ttt_client)