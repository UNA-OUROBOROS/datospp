datospp_inc = include_directories('include')

datospp_sources = []
datospp_args = []
datospp_link = []
datospp_deps = []
datospp_incl = [datospp_inc]

extras_support = get_option('extras')

if extras_support
    subdir('extras')
    datospp_lib = shared_library('datospp',
                            datospp_sources,
                            include_directories : datospp_incl,
                            cpp_args: datospp_args,
                            dependencies : datos_deps)
    datos_dep = declare_dependency(link_with : datospp_lib,
                            include_directories : datospp_incl,
                            dependencies : datospp_deps)
else
    datospp_dep = declare_dependency(
        include_directories: datospp_inc
    )
endif

