conf_data = configuration_data()
conf_data.set('FORMATVERSION', '1.0.0')
conf_data.set('LIBPATH', 'lib@0@.so.0'.format(meson.project_name().to_lower()))
conf_data.set('APIVERSION', '1.1.125')

configure_file(input: '@0@.json.in'.format(meson.project_name()),
               output: '@0@.json'.format(meson.project_name()),
               configuration: conf_data,
               install: true,
               install_dir : join_paths(get_option('datadir'), 'vulkan', 'implicit_layer.d'))
