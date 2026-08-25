add_executable(ministl_example
        version_example.cpp
)

target_link_libraries(
        ministl_example
        PRIVATE
        ministl::ministl
)