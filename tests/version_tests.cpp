#include <ministl/version.hpp>

#include <cstdlib>
#include <iostream>
#include <string_view>

int main()
{
	constexpr std::string_view expected_version{"0.1.0"};

	if (ministl::version() != expected_version)
	{
		std::cerr
			<< "Expected version: " << expected_version
			<< ", actual version: " << ministl::version()
			<< '\n';

		return EXIT_FAILURE;
	}

	std::cout << "Mini STL version test passed.\n";
	return EXIT_SUCCESS;
}