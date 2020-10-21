# author: greyshell

cmake_minimum_required(VERSION 3.9)
project(O2 C)
set(CMAKE_C_STANDARD 99)
include(GNUInstallDirs)

# Create the shared library
file(GLOB SOURCES src/*.c)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Install the .so file at /usr/local/lib/
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

# Install .h files at /usr/local/include
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})