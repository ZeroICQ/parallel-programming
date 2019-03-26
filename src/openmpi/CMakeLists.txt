find_package(MPI REQUIRED)
#include_directories(main ${MPI_INCLUDE_PATH})
#target_link_libraries(main ${MPI_C_LIBRARIES})