datospp_inc = include_directories('include')

datospp_sources = []
datospp_args = []
datospp_link = []
datospp_deps = []

# no es necesario ya que solo tenemos cabeceras
#datospp_lib = shared_library('datospp',
#                        datospp_sources,
#                        include_directories : datospp_inc,
#                        cpp_args: datospp_args,
#                        dependencies : datos_deps)

datospp_dep = declare_dependency(
    #link_with: datospp_lib,
    include_directories: datospp_inc
)