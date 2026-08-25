add_executable(
        lifetime_tests
        lifetime_tests.cpp)

target_link_libraries(
        lifetime_tests
        PRIVATE
        ministl)

add_test(
        NAME lifetime_tests
        COMMAND lifetime_tests)

add_executable(raw_buffer_tests
        raw_buffer_tests.cpp
)

target_link_libraries(raw_buffer_tests
        PRIVATE ministl
)

add_test(
        NAME raw_buffer_tests
        COMMAND raw_buffer_tests
)