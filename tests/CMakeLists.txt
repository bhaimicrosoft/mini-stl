add_executable(ministl_tests version_tests.cpp)

target_link_libraries(ministl_tests PRIVATE ministl::ministl)

add_test(NAME ministl.version COMMAND ministl_tests)