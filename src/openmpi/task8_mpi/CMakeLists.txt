add_executable(task8_mpi main.cpp)
setupmpitarget(task8_mpi)

MESSAGE(WARNING ${MPI_C_LIBRARIES})