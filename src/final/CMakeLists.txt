#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

include_directories(".")

add_executable(chat_server chat_server.cpp)
add_executable(chat_client chat_client.cpp)

setupmpitarget(chat_server)
setupmpitarget(chat_client)