project('vkBasalt', ['c', 'cpp'], default_options: ['c_std=c11', 'cpp_std=c++2a'])

vkBasalt_include_path = include_directories('./include', './include/spirv')

if get_option('with_so')
    subdir('src')
endif

if get_option('with_json')
    subdir('config')
endif
