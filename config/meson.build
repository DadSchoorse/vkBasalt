data_dir = get_option('datadir')

vulkan_layer_dir = join_paths(data_dir, 'vulkan', 'implicit_layer.d')

configure_file(
    input : 'vkBasalt.json.in',
    output : 'vkBasalt.json',
    configuration : {'ld_lib_dir_vkbasalt' : ld_lib_dir_vkbasalt},
    install : true,
    install_dir : vulkan_layer_dir,
)
