function(setupmpitarget target)
    include_directories(${target} ${MPI_INCLUDE_PATH})
    target_link_libraries(${target} ${MPI_C_LIBRARIES})
endfunction()