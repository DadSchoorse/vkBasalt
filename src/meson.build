src_directory = include_directories('.')

common_sources = [
    'basalt.cpp',
    'command_buffer.cpp',
    'compute_pipeline.cpp',
    'descriptor_set.cpp',
    'image_view.cpp',
    'shader.cpp',
]

common_headers = [
    'command_buffer.hpp',
    'compute_pipeline.hpp',
    'descriptor_set.hpp',
    'image_view.hpp',
    'shader.hpp',
]

vulkan_dep = dependency('vulkan')

sources = [
    common_headers,
    common_sources
]

deps = [
    vulkan_dep
]

vkbasalt = library('vkbasalt',
                 sources,
                 dependencies: deps,
                 version: meson.project_version(),
                 install: true)
