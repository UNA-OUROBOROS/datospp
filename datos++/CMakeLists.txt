cmake_minimum_required(VERSION 3.10)
project(foro VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(src_include
    include/datos++/lista.hpp
    include/datos++/lista_doble.hpp
    include/datos++/cola_prioridad.hpp
    include/datos++/vector.hpp
    include/datos++/heap.hpp
)

set(src
    ${src_include}
    #src/source.cpp
)

add_executable(source ${src} src/source.cpp)
target_include_directories(source PRIVATE include)

if (MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()
