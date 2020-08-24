cmake_minimum_required(VERSION 3.10)
project(foro VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

set(src_include
    include/lista.hpp
)

set(src
    ${src_include}
    src/source.cpp
    src/lista.cpp
)


add_executable(foro ${src})
target_include_directories(foro PRIVATE include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
