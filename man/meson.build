manpages = ['as.1', 'bitcode_strip.1', 'cmpdylib.1', 'codesign_allocate.1', 'ctf_insert.1',
  'install_name_tool.1', 'libtool.1', 'lipo.1', 'llvm-otool.1', 'otool-classic.1', 'nmedit.1',
  'otool-classic.1', 'pagestuff.1', 'segedit.1', 'size.1', 'strings.1', 'strip.1']

foreach m : manpages
  install_data(m,
    install_dir : get_option('mandir') / 'man1',
    rename : get_option('program-prefix') + m)
endforeach

install_symlink(get_option('program-prefix') + 'otool.1',
  pointing_to : get_option('program-prefix') + 'otool-classic.1',
  install_dir : get_option('mandir') / 'man1')

install_symlink(get_option('program-prefix') + 'ranlib.1',
  pointing_to : get_option('program-prefix') + 'libtool.1',
  install_dir : get_option('mandir') / 'man1')

install_symlink(get_option('program-prefix') + 'size-classic.1',
  pointing_to : get_option('program-prefix') + 'size.1',
  install_dir : get_option('mandir') / 'man1')

install_data('nm.1',
  install_dir : get_option('mandir') / 'man1',
  rename : get_option('program-prefix') + 'nm-classic.1')
