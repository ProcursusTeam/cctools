as_arm = executable('as', as_srcs, as_arm_srcs,
  link_with : libstuff,
  include_directories : [incdirs, as_inc],
  c_args : ['-DARM', '-DNeXT_MOD'],
  install_dir : get_option('libexecdir') / 'as' / 'arm',
  install : true)
