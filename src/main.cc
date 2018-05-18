#include<iostream>
#include<list>
#include<string>
#include<cstdlib>
#include<internal_fgrep.h>
#include<fgrep.h>

void usage() {
	std::cout <<
		"usage:" << std::endl
		<< "  " << "-f [regex]" << std::endl
		<< "  " << "  " << "regex to search file pattern" << std::endl
		<< "  " << "-r [regex]" << std::endl
		<< "  " << "  " << "regex to match " << std::endl
		<< "  " << "-p [dir]" << std::endl
		<< "  " << "  " << "path to root dir to find(default is current dir)" << std::endl
		<< "  " << "--l" << std::endl
		<< "  " << "  " << "load whole file into buffer and try regex" << std::endl
		<< "  " << "--t" << std::endl
		<< "  " << "  " << "turbo mode(use multi thread and high memory)" << std::endl
		<< "  " << "--of" << std::endl
		<< "  " << "  " << "only find files(ignore -r)" << std::endl
		<< "  " << "--os" << std::endl
		<< "  " << "  " << "only show status(not print matched string)" << std::endl
		<< "  " << "--f-or" << std::endl
		<< "  " << "  " << "allow multiple -f option and combine those with logical sum" << std::endl
		<< "  " << "--f-and" << std::endl
		<< "  " << "  " << "allow multiple -f option and combine those with logical multiply" << std::endl
		<< "  " << "--r-or" << std::endl
		<< "  " << "  " << "allow multiple -r option and combine those with logical sum" << std::endl
		<< "  " << "--r-and" << std::endl
		<< "  " << "  " << "allow multiple -r option and combine those with logical multiply" << std::endl
		;
}

int main(int argc, char ** argv) {
	std::list<std::string> args;
	for(int i = 0; i < argc; ++i) {
		args.push_back(argv[i]);
	}

	if(argc <= 1) {
		usage();
	}

  return EXIT_SUCCESS;
}
