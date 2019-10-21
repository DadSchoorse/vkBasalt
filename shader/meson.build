glsl_compiler = find_program('glslangValidator', required: true)

shaders_in = [
    'cas.comp.glsl'
]

shaders_out = [
    'cas.comp.spv'
]

glsl_generator = custom_target('shaders-gen',
    input: shaders_in,
    output: shaders_out,
    command: [glsl_compiler, '-V', '@INPUT@', '-o', '@OUTPUT@'],
    install: true,
    install_dir: join_paths(get_option('datadir'), meson.project_name(), 'shader')
)
