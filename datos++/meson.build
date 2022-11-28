datospp_inc = include_directories('include')

datospp_srcs = []
datospp_args = []
datospp_link = []
datospp_deps = []
datospp_incl = [datospp_inc]

if extras_support
    subdir('extras')
    datospp_srcs += datospp_extras_srcs
    datospp_args += datospp_extras_args
    datospp_link += datospp_extras_link
    datospp_deps += datospp_extras_deps
    datospp_incl += datospp_extras_incl
    datospp_lib = shared_library('datospp',
                            datospp_srcs,
                            include_directories : datospp_incl,
                            cpp_args: datospp_args,
                            dependencies : datospp_deps)
    datospp_dep = declare_dependency(link_with : datospp_lib,
                            include_directories : datospp_incl,
                            dependencies : datospp_deps)
else
    datospp_dep = declare_dependency(
        include_directories: datospp_inc
    )
endif

