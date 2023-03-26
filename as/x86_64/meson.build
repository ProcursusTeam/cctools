as_x86_64 = executable('as', as_srcs, as_i386_srcs,
  link_with : libstuff,
  include_directories : [incdirs, as_inc],
  c_args : ['-DI386', '-DI486', '-DI586', '-DI686', '-DARCH64', '-DNeXT_MOD'],
  install_dir : get_option('libexecdir') / 'as' / 'x86_64',
  install : true)
