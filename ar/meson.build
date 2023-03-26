ar_srcs = files('print.c', 'misc.c', 'ar.c', 'extract.c',
                'contents.c', 'archive.c', 'append.c',
                'move.c', 'replace.c', 'delete.c',
                'archive.h', 'extern.h', 'pathnames.h')

ar = executable(get_option('program-prefix') + 'ar', ar_srcs,
  link_with : libstuff,
  include_directories : incdirs,
  install : true)

install_data('ar.1',
             install_dir : get_option('mandir') / 'man1',
             rename : get_option('program-prefix') + 'ar.1')

