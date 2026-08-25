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