add_executable(task17_mpi_server server.cpp)
setupmpitarget(task17_mpi_server)

add_executable(task17_mpi_client client.cpp)
setupmpitarget(task17_mpi_client)

