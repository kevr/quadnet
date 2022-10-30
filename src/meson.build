# googletest dependencies
gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')
gtest_main_dep = gtest_proj.get_variable('gtest_main_dep')

# project executable
exe = executable(
  'quadnet',
  'main.cpp',
  install : true
)
