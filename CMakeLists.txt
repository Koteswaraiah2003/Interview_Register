cmake_minimum_required(VERSION 3.16)

project(Interviwer_Register LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Interviwer_Register main.cpp
    canditate.h canditate.cpp
    interviwer.h interviwer.cpp
    interviewmanager.h interviewmanager.cpp
    datetime.h datetime.cpp
    mylist.h mylist.cpp
    functions.cpp
    canditatelist.h canditatelist.cpp
    interviewlist.h interviewlist.cpp)

include(GNUInstallDirs)
install(TARGETS Interviwer_Register
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
