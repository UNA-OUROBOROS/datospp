test_sources = [
    'source.cpp',
    'vector-test.cpp'
]

test_dependencies = [
    catch2_dep,
    datospp_dep
]

testexe = executable('testexe', test_sources,
                     include_directories : datospp_inc,
                     #link_with : datospp_lib,
                     dependencies: test_dependencies)
test('datos++ test', testexe)