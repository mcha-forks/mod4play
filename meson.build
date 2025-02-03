project(
  'mod4play',
  'c',
  version: '1.3',
  license: 'BSD-3-Clause AND MIT',
  license_files: ['LICENSE', 'example/LICENSE', 'example/sokol/LICENSE'],
  default_options: [
    'warning_level=3',
    'c_std=gnu11,c11,gnu99,c99,gnu89,c89',
    'default_library=static',
  ],
  meson_version: '>=1.1.0',
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required: false)

inc = include_directories('.')

m4p_lib = library(
  'm4p',
  'm4p.c',
  dependencies: m_dep,
  implicit_include_directories: false,
  include_directories: inc,
)

m4p_dep = declare_dependency(
  link_with: m4p_lib,
  include_directories: inc,
)

meson.override_dependency('m4p', m4p_dep)

subdir('example')
