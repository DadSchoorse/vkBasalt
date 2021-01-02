reshade_src = [
    'effect_codegen_spirv.cpp',
    'effect_expression.cpp',
    'effect_lexer.cpp',
    'effect_parser.cpp',
    'effect_preprocessor.cpp',
    'effect_symbol_table.cpp',
]


cpp_args_reshade = cpp.get_supported_arguments(['-Wno-unknown-pragmas'])


reshade_lib = static_library('reshade', reshade_src,
    include_directories : vkBasalt_include_path,
    cpp_args : cpp_args_reshade,
    )

reshade_dep = declare_dependency(
    link_with : [ reshade_lib ])