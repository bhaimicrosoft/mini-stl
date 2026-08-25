function(add_ministl_test TEST_NAME)
    add_executable(
            ${TEST_NAME}
            ${TEST_NAME}.cpp
    )

    target_link_libraries(
            ${TEST_NAME}
            PRIVATE ministl
    )

    add_test(
            NAME ${TEST_NAME}
            COMMAND ${TEST_NAME}
    )
endfunction()

add_ministl_test(version_tests)
add_ministl_test(raw_buffer_tests)
add_ministl_test(lifetime_tests)
add_ministl_test(uninitialized_tests)

