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
    input: spv_generator.process(shader_src),
    output: '@BASENAME@.spv',
    command: [spirv_opt, '@INPUT@', '-O', '-o', '@OUTPUT@'],
    build_by_default: true,
    install: true,
    install_dir: join_paths(get_option('datadir'), meson.project_name(), 'shader')
  )
endforeach
