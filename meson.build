project(
    'datos++', 'cpp',
    default_options: ['cpp_std=c++17'],
    version: '1.0.0 v2021',
    license: 'BSD-3'
)
version = '1.0.0 v2021'

catch2_dep = dependency(
                'catch2',
                fallback: ['catch2', 'catch2_dep']
)

extras_support = get_option('extras_support')

subdir('datos++')
subdir('test')

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : datospp_dep,
				 version : version,
				 name : 'datos++',
				 filebase : 'datos++',
				 description : 'Estructuras de datos para el uso de cursos en la Universidad Nacional.')