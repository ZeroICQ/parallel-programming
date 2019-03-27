find_package(MPI REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/CMakeModules)

include(SetupMpi)
add_subdirectory(task1_mpi)
add_subdirectory(task2_mpi)
add_subdirectory(task3_mpi)