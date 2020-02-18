src_directory = include_directories('.')

vulkan = dependency('vulkan')

reshade_dir = join_paths('..', 'reshade')
reshade_spirv_include_dir = include_directories(join_paths(reshade_dir, 'deps/spirv/include/spirv/unified1'))
reshade_effects = static_library(
  'reshade-effects',
  [
    join_paths(reshade_dir, 'source/effect_lexer.cpp'),
    join_paths(reshade_dir, 'source/effect_expression.cpp'),
    join_paths(reshade_dir, 'source/effect_preprocessor.cpp'),
    join_paths(reshade_dir, 'source/effect_codegen_spirv.cpp'),
    join_paths(reshade_dir, 'source/effect_symbol_table.cpp'),
    join_paths(reshade_dir, 'source/effect_parser.cpp')
  ],
  include_directories: [reshade_spirv_include_dir],
  cpp_args: ['-Wno-missing-field-initializers', '-Wno-switch', '-Wno-unknown-pragmas', '-Wno-char-subscripts'],
  pic: true
)

vkbasalt = shared_library(
  meson.project_name().to_lower(),
  [
    'logical_swapchain.cpp',
    'effect_cas.cpp',
    'sampler.cpp',
    'renderpass.cpp',
    'effect_lut.cpp',
    'effect_reshade.cpp',
    'format.cpp',
    'framebuffer.cpp',
    'effect_smaa.cpp',
    'command_buffer.cpp',
    'shader.cpp',
    'stb_image.cpp',
    'fake_swapchain.cpp',
    'lut_cube.cpp',
    'util.cpp',
    'effect_transfer.cpp',
    'descriptor_set.cpp',
    'effect_simple.cpp',
    'image.cpp',
    'graphics_pipeline.cpp',
    'stb_image_resize.cpp',
    'buffer.cpp',
    'basalt.cpp',
    'image_view.cpp',
    'memory.cpp',
    'effect_deband.cpp',
    'config.cpp',
    'effect.cpp',
    'effect_fxaa.cpp',
    'reshade_uniforms.cpp'
  ],
  include_directories: [reshade_spirv_include_dir],
  cpp_args: ['-Wno-unused-parameter'],
  dependencies: [vulkan],
  link_with: [reshade_effects],
  install: true
)
