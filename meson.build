project('cctools', ['c', 'cpp'],
  version : '986',
  default_options : ['c_std=gnu11', 'cpp_std=gnu++14'])

add_global_arguments('-DCURRENT_PROJECT_VERSION="' + meson.project_version() + '"', language : 'c')
add_global_arguments('-DCODEDIRECTORY_SUPPORT', language : 'c')
add_global_arguments('-DLTO_SUPPORT', language : 'c')

ld64_proj = subproject('ld64', required : false)
if ld64_proj.found()
  libprunetrie_dep = ld64_proj.get_variable('libprunetrie_dep')
endif

incdirs = []

subdir('ar.d')
subdir('as.d')
subdir('include')
subdir('libstuff')
subdir('misc')
subdir('otool')
subdir('man')

subdir('EXTERNAL_HEADERS')

llvm_dep = dependency('llvm', modules : ['lto'])

libstuff = static_library('stuff', libstuff_srcs,
  dependencies : llvm_dep.partial_dependency(includes : true, compile_args : true),
  include_directories : [incdirs, libstuff_inc])

ar = executable(get_option('program-prefix') + 'ar', ar_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

as = executable(get_option('program-prefix') + 'as', as_driver_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

as_arm = executable('as_arm', as_srcs, as_arm_srcs,
  link_with : libstuff,
  include_directories : [incdirs, as_inc],
  c_args : ['-DARM', '-DNeXT_MOD'],
  install_dir : get_option('libexecdir'),
  install : true)

as_i386 = executable('as_i386', as_srcs, as_i386_srcs,
  link_with : libstuff,
  include_directories : [incdirs, as_inc],
  c_args : ['-DI386', '-DI486', '-DI586', '-DI686', '-DNeXT_MOD'],
  install_dir : get_option('libexecdir'),
  install : true)

as_x86_64 = executable('as_x86_64', as_srcs, as_i386_srcs,
  link_with : libstuff,
  include_directories : [incdirs, as_inc],
  c_args : ['-DI386', '-DI486', '-DI586', '-DI686', '-DARCH64', '-DNeXT_MOD'],
  install_dir : get_option('libexecdir'),
  install : true)

bitcode_strip = executable(get_option('program-prefix') + 'bitcode_strip', bitcode_strip_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

cmpdylib = executable(get_option('program-prefix') + 'cmpdylib', cmpdylib_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

codesign_allocate = executable(get_option('program-prefix') + 'codesign_allocate', codesign_allocate_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

install_symlink(get_option('program-prefix') + 'codesign_allocate-p',
  pointing_to : get_option('program-prefix') + 'codesign_allocate',
  install_dir : get_option('bindir'))

ctf_insert = executable(get_option('program-prefix') + 'ctf_insert', ctf_insert_srcs,
  link_with : libstuff,
  include_directories : [incdirs, libstuff_inc],
  install : true)

install_name_tool = executable(get_option('program-prefix') + 'install_name_tool', install_name_tool_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

libtool = executable(get_option('program-prefix') + 'libtool', libtool_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

install_symlink(get_option('program-prefix') + 'ranlib',
  pointing_to : get_option('program-prefix') + 'libtool',
  install_dir : get_option('bindir'))

lipo = executable(get_option('program-prefix') + 'lipo', lipo_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

llvm_otool = executable(get_option('program-prefix') + 'llvm-otool', llvm_otool_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  c_args : ['-DEFI_SUPPORT', '-DLLVM_OTOOL'],
  install : true)

install_symlink(get_option('program-prefix') + 'otool',
  pointing_to : get_option('program-prefix') + 'llvm-otool',
  install_dir : get_option('bindir'))

nm_classic = executable(get_option('program-prefix') + 'nm-classic', nm_classic_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

nmedit = executable(get_option('program-prefix') + 'nmedit', nmedit_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  c_args : ['-DNMEDIT'],
  install : true)

otool_classic = executable(get_option('program-prefix') + 'otool-classic', otool_classic_srcs,
  link_with : libstuff,
  include_directories : [incdirs, otool_classic_inc],
  c_args : ['-DEFI_SUPPORT', '-DOTOOL'],
  link_language : 'cpp', # otool uses __cxa_demangle() from libc++
  install : true)

pagestuff = executable(get_option('program-prefix') + 'pagestuff', pagestuff_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

segedit = executable(get_option('program-prefix') + 'segedit', segedit_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

size_classic = executable(get_option('program-prefix') + 'size-classic', size_classic_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

install_symlink(get_option('program-prefix') + 'size',
  pointing_to : get_option('program-prefix') + 'size-classic',
  install_dir : get_option('bindir'))

strings = executable(get_option('program-prefix') + 'strings', strings_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

strip = executable(get_option('program-prefix') + 'strip', strip_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  dependencies : ld64_proj.found() ? libprunetrie_dep : [],
  c_args : ld64_proj.found() ? ['-DTRIE_SUPPORT'] : [],
  install : true)
