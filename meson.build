project ('sqlib', ['cpp'],
        version: '1.0',
        default_options: [
           'cpp_std=c++17',
           'c_std=gnu99',
           'optimization=2',
           'debug=true',
           'default_library=static'
          ]
        )

add_global_arguments (['-Werror'], language: 'cpp')
inc_dir = include_directories ('.')

sqlite = subproject ('sqlite')
sqlite_dep = sqlite.get_variable ('sqlite_dep')

subdir ('tests')
