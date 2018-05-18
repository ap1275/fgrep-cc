#include<iostream>
#include<list>
#include<string>
#include<cstdlib>
#include<fgrep.h>

void usage() {
  std::cout <<
    "usage:" << std::endl
    << "  " << "-f [regex]" << std::endl
    << "  " << "  " << "file pattern for search using regex" << std::endl
    << "  " << "-p [dir]" << std::endl
    << "  " << "  " << "path to root dir to find(default is current dir)" << std::endl
    << "  " << "-r [regex]" << std::endl
    << "  " << "  " << "regex to match each lines" << std::endl
    << "  " << "-s stdin" << std::endl
    << "  " << "  " << "stdin as a text" << std::endl
    << "  " << "--fa" << std::endl
    << "  " << "  " << "allow multiple -f option and combine those with logical multiply" << std::endl
    << "  " << "--fo" << std::endl
    << "  " << "  " << "allow multiple -f option and combine those with logical sum" << std::endl
    << "  " << "--l" << std::endl
    << "  " << "  " << "load whole file into buffer and try regex" << std::endl
    << "  " << "--of" << std::endl
    << "  " << "  " << "only find files" << std::endl
    << "  " << "--os" << std::endl
    << "  " << "  " << "only show status(not print matched string)" << std::endl
    << "  " << "--ra" << std::endl
    << "  " << "  " << "allow multiple -r option and combine those with logical multiply" << std::endl
    << "  " << "--ro" << std::endl
    << "  " << "  " << "allow multiple -r option and combine those with logical sum" << std::endl
    << "  " << "--t" << std::endl
    << "  " << "  " << "turbo mode(use multi thread and high memory)" << std::endl
    ;
}

int main(int argc, char ** argv) {
  if(argc <= 1) {
    usage();
    return EXIT_SUCCESS;
  }

  bool fo = false;
  bool fa = false;
  bool ro = false;
  bool ra = false;
  bool l = false;
  bool t = false;
  bool of = false;
  bool os = false;
  bool use_stdin = false;

  g::fgrep grep;

  for(int i = 0; i < argc; ++i) {
    if(strcmp("-f", argv[i]) == 0 && i + 1 < argc && *argv[i + 1] != '-') grep.fpattern.push_back(argv[i + 1]);
    if(strcmp("-p", argv[i]) == 0 && i + 1 < argc && *argv[i + 1] != '-') grep.root = std::string(argv[i + 1]);
    if(strcmp("-r", argv[i]) == 0 && i + 1 < argc && *argv[i + 1] != '-') grep.rpattern.push_back(argv[i + 1]);
    if(strcmp("-s", argv[i]) == 0) use_stdin = true;
    if(strcmp("--fa", argv[i]) == 0) fa = true;
    if(strcmp("--fo", argv[i]) == 0) fo = true;
    if(strcmp("--l", argv[i]) == 0) l = true;
    if(strcmp("--of", argv[i]) == 0) of = true;
    if(strcmp("--os", argv[i]) == 0) os = true;
    if(strcmp("--ra", argv[i]) == 0) ra = true;
    if(strcmp("--ro", argv[i]) == 0) ro = true;
    if(strcmp("--t", argv[i]) == 0) t = true;
  }

  if(
    (fo && fa) ||
    (ro && ra) ||
    (of && os) ||
    (of && ! grep.rpattern.empty()) ||
    (use_stdin && (grep.rpattern.empty() || ! grep.root.empty() || ! grep.fpattern.empty() || of || fo || fa)) ||
    (grep.fpattern.empty() && grep.rpattern.empty() && ! use_stdin)
  )
  {
    usage();
    return EXIT_SUCCESS;
  }

  grep.flag = g::fgrep::flags::none;
  if(fo) grep.flag |= g::fgrep::fo;
  if(fa) grep.flag |= g::fgrep::flags::fa;
  if(ro) grep.flag |= g::fgrep::flags::ro;
  if(ra) grep.flag |= g::fgrep::flags::ra;
  if(l) grep.flag |= g::fgrep::flags::l;
  if(t) grep.flag |= g::fgrep::flags::t;
  if(of) grep.flag |= g::fgrep::flags::of;
  if(os) grep.flag |= g::fgrep::flags::os;
  if(use_stdin) grep.flag |= g::fgrep::flags::use_stdin;


  return EXIT_SUCCESS;
}
