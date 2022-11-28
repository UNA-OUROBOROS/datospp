test_sources = [
    'source.cpp',
    'vector-test.cpp',
    'linked_list-test.cpp'
]

test_dependencies = [
    catch2_dep,
    datospp_dep
]

if extras_support
    subdir('extras')
    test_sources += datospp_test_extras_srcs
endif


testexe = executable('testexe', test_sources,
                     include_directories : datospp_inc,
                     #link_with : datospp_lib,
                     dependencies: test_dependencies)
test('datos++ test', testexe)