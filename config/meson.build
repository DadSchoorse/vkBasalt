conf_data = configuration_data()
conf_data.set('LIBPATH', 'lib@0@.so'.format(meson.project_name().to_lower()))

configure_file(input: '@0@.json.in'.format(meson.project_name()),
               output: '@0@.json'.format(meson.project_name()),
               configuration: conf_data,
               install: true,
               install_dir : join_paths(get_option('datadir'), 'vulkan', 'implicit_layer.d'))

install_data(['vkBasalt.conf'],
               install_dir: join_paths(get_option('datadir'), meson.project_name()))
