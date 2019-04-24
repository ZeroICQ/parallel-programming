add_executable(task16_mpi_master master.cpp)
setupmpitarget(task16_mpi_master)

add_executable(task16_mpi_slave slave.cpp)
setupmpitarget(task16_mpi_slave)

