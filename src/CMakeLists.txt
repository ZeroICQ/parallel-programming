FILE(GLOB SRC "./*.cpp")

SET(CUSTOM_COMPILE_FLAGS "-Wall -pedantic")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CUSTOM_COMPILE_FLAGS}")

add_executable(main ${SRC})

include_directories(main ${MPI_INCLUDE_PATH})
target_link_libraries(main ${MPI_C_LIBRARIES})

if (MINGW)
    get_filename_component( Mingw_Path ${CMAKE_CXX_COMPILER} PATH )
    set(MINGW_RUNTIME_LIBS
            ${Mingw_Path}/libgcc_s_seh-1.dll
            ${Mingw_Path}/libstdc++-6.dll
            ${Mingw_Path}/libwinpthread-1.dll)

    #    message(STATUS " - Coping system-libraries: MinGW DLLs.  ${Mingw_Path}")

    add_custom_target(copyDLL)
    foreach(dll  ${MINGW_RUNTIME_LIBS})
        add_custom_command(TARGET copyDLL POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E
                copy ${dll} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endforeach()

endif (MINGW)

