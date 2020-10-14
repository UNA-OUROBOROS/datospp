cmake_minimum_required(VERSION 3.10)
project(foro VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

set(src_include
    include/lista.hpp
    include/lista_doble.hpp
    include/cola_prioridad.hpp
    include/vector.hpp
    include/heap.hpp
)

set(src
    ${src_include}
    #src/source.cpp
)


#add_executable(foro ${src})
add_executable(source ${src} src/source.cpp)
target_include_directories(source PRIVATE include)
add_executable(problemas-tda ${src} ejercicios/problemas-tda/problemas-tda.cpp)
target_include_directories(problemas-tda PRIVATE include)


if (MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra -pedantic -std=c++20)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
