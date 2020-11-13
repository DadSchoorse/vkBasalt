subdir('shader')
subdir('reshade')

vkBasalt_src = [
    'basalt.cpp',
    'buffer.cpp',
    'command_buffer.cpp',
    'config.cpp',
    'descriptor_set.cpp',
    'effect_cas.cpp',
    'effect.cpp',
    'effect_deband.cpp',
    'effect_dls.cpp',
    'effect_fxaa.cpp',
    'effect_lut.cpp',
    'effect_reshade.cpp',
    'effect_simple.cpp',
    'effect_smaa.cpp',
    'effect_transfer.cpp',
    'fake_swapchain.cpp',
    'format.cpp',
    'framebuffer.cpp',
    'graphics_pipeline.cpp',
    'image.cpp',
    'image_view.cpp',
    'keyboard_input.cpp',
    'keyboard_input_x11.cpp',
    'logger.cpp',
    'logical_swapchain.cpp',
    'lut_cube.cpp',
    'memory.cpp',
    'renderpass.cpp',
    'reshade_uniforms.cpp',
    'sampler.cpp',
    'shader.cpp',
    'stb_image.cpp',
    'stb_image_resize.cpp',
    'util.cpp',
]

x11_dep = dependency('x11')

vulkan_dep = []
if get_option('vk_force_fallback')
    vulkan_dep += subproject('vulkan-headers').get_variable('vulkan_headers_dep')
    vulkan_dep += subproject('vulkan-validationlayers').get_variable('vulkan_validationlayers_dep')
endif


shared_library(meson.project_name().to_lower(), 
    vkBasalt_src, shader_include,
    dependencies : [vulkan_dep, x11_dep, reshade_dep],
    install : true,
    install_dir : lib_dir)
