function(setupmpitarget target)
    include_directories(${target} ${MPI_CXX_INCLUDE_PATH})
    target_link_libraries(${target} ${MPI_CXX_LIBRARIES})
endfunction()