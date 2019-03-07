cmake_minimum_required(VERSION 3.6)
project(parallel-programming)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
function()
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
                copy_if_different ${dll} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endforeach()

endif (MINGW)

