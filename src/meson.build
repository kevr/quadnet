# googletest dependencies
gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')
gtest_main_dep = gtest_proj.get_variable('gtest_main_dep')

quadnet = declare_dependency(
  include_directories : [inc]
)

test_deps = [quadnet, gtest_dep, gmock_dep, gtest_main_dep]

# tests
random_test = executable(
  'random.test',
  'random.test.cpp',
  dependencies : test_deps
)
test('random test', random_test)

main_test = executable(
  'main.test',
  'main.test.cpp',
  dependencies : test_deps
)
test('main test', main_test)

# project executable
exe = executable(
  'quadnet',
  'main.cpp',
  install : true,
  dependencies : [quadnet]
)
