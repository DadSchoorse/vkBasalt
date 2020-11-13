reshade_src = [
    'effect_codegen_spirv.cpp',
    'effect_expression.cpp',
    'effect_lexer.cpp',
    'effect_parser.cpp',
    'effect_preprocessor.cpp',
    'effect_symbol_table.cpp',
]

reshade_lib = static_library('reshade', reshade_src)

reshade_dep = declare_dependency(
    link_with : [ reshade_lib ])
