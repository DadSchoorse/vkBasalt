project('vkBasalt', 'cpp', default_options: ['c_std=c11', 'cpp_std=c++2a'])

vulkan = dependency('vulkan')

add_project_link_arguments(['-lstdc++fs'], language: 'cpp')

reshade_include_dir = include_directories('reshade/deps/spirv/include/spirv/unified1')
reshade_effects = static_library(
  'reshade-effects',
  [
    'reshade/source/effect_lexer.cpp',
    'reshade/source/effect_expression.cpp',
    'reshade/source/effect_preprocessor.cpp',
    'reshade/source/effect_codegen_spirv.cpp',
    'reshade/source/effect_symbol_table.cpp',
    'reshade/source/effect_parser.cpp'
  ],
  include_directories: [reshade_include_dir],
  cpp_args: ['-Wno-missing-field-initializers', '-Wno-switch', '-Wno-unknown-pragmas', '-Wno-char-subscripts'],
  pic: true
)

vkbasalt = shared_library(
  'vkbasalt',
  [
    'src/logical_swapchain.cpp',
    'src/effect_cas.cpp',
    'src/sampler.cpp',
    'src/renderpass.cpp',
    'src/effect_lut.cpp',
    'src/effect_reshade.cpp',
    'src/format.cpp',
    'src/framebuffer.cpp',
    'src/effect_smaa.cpp',
    'src/command_buffer.cpp',
    'src/shader.cpp',
    'src/stb_image.cpp',
    'src/fake_swapchain.cpp',
    'src/lut_cube.cpp',
    'src/util.cpp',
    'src/effect_transfer.cpp',
    'src/descriptor_set.cpp',
    'src/effect_simple.cpp',
    'src/image.cpp',
    'src/graphics_pipeline.cpp',
    'src/stb_image_resize.cpp',
    'src/buffer.cpp',
    'src/basalt.cpp',
    'src/image_view.cpp',
    'src/memory.cpp',
    'src/effect_deband.cpp',
    'src/config.cpp',
    'src/effect.cpp',
    'src/effect_fxaa.cpp',
    'src/reshade_uniforms.cpp'
  ],
  include_directories: [reshade_include_dir],
  cpp_args: ['-Wno-unused-parameter'],
  dependencies: [vulkan],
  link_with: [reshade_effects],
  install: true
)

install_data(['config/vkBasalt.conf'], install_dir: get_option('datadir') / 'vkBasalt')

m4 = find_program('m4')

# TODO: This libdir thing seems like a hack, and should probably be fixed up by someone better at meson
if get_option('libdir') == 'lib32'
  json_definition_32 = custom_target(
    'vkBasalt32.json',
    output: 'vkBasalt32.json',
    input: 'config/vkBasalt32.json',
    command: [m4, '-D__lib__=/usr/lib32/libvkbasalt.so', '@INPUT@'],
    capture: true,
    install: true,
    install_dir: get_option('datadir') + '/vulkan/implicit_layers.d'
  )
else
  full_libpath = get_option('prefix') + '/' + get_option('libdir') + '/libvkbasalt.so'
  json_definition_64 = custom_target(
    'vkBasalt64.json',
    output: 'vkBasalt64.json',
    input: 'config/vkBasalt64.json',
    command: [m4, '-D__lib__=' + full_libpath, '@INPUT@'],
    capture: true,
    install: true,
    install_dir: get_option('datadir') + '/vulkan/implicit_layers.d'
  )
endif

spirv_opt = find_program('spirv-opt')
glslang_validator = find_program('glslangValidator')

shader_sources = [
  'cas.frag.glsl',
  'smaa_blend.frag.glsl',
  'smaa_neighbor.frag.glsl',
  'smaa_edge_luma.frag.glsl',
  'fxaa.frag.glsl',
  'deband.frag.glsl',
  'smaa_blend.vert.glsl',
  'smaa_edge_color.frag.glsl',
  'full_screen_triangle.vert.glsl',
  'smaa_neighbor.vert.glsl',
  'lut.frag.glsl',
  'smaa_edge.vert.glsl'
]

spv_generator = generator(
  glslang_validator,
  arguments: ['-V', '@INPUT@', '-o', '@OUTPUT@'],
  output: '@BASENAME@.spv'
)

foreach shader_src : shader_sources
  custom_target(
    shader_src,
    input: spv_generator.process('shader/' + shader_src),
    output: '@BASENAME@.spv',
    command: [spirv_opt, '@INPUT@', '-O', '-o', '@OUTPUT@'],
    build_by_default: true,
    install: true,
    install_dir: get_option('datadir') + '/vkBasalt/shader'
  )
endforeach
