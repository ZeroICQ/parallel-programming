#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fopenmp")

include_directories(".")

add_executable(chat_server chat_server.cpp common.cpp)
add_executable(chat_client chat_client.cpp common.cpp)

setupmpitarget(chat_server)
setupmpitarget(chat_client)
