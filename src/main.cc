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

  std::list<std::string> f;
  std::string p;
  std::list<std::string> r;
  std::string s;

  for(int i = 0; i < argc; ++i) {
    if(strcmp("-f", argv[i]) == 0 && i + 1 < argc && *argv[i + 1] != '-') f.push_back(argv[i + 1]);
    if(strcmp("-p", argv[i]) == 0 && i + 1 < argc && *argv[i + 1] != '-') p = std::string(argv[i + 1]);
    if(strcmp("-r", argv[i]) == 0 && i + 1 < argc && *argv[i + 1] != '-') r.push_back(argv[i + 1]);
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
    (of && ! r.empty()) ||
    (use_stdin && (r.empty() || ! p.empty() || ! f.empty() || of || fo || fa)) ||
    (f.empty() && r.empty() && ! use_stdin)
  )
  {
    usage();
    return EXIT_SUCCESS;
  }

  uint64_t flag;
  flag = static_cast<uint64_t>(g::fgrep::flags::none);
  if(fo) flag |= static_cast<uint64_t>(g::fgrep::flags::fo);
  if(fa) flag |= static_cast<uint64_t>(g::fgrep::flags::fa);
  if(ro) flag |= static_cast<uint64_t>(g::fgrep::flags::ro);
  if(ra) flag |= static_cast<uint64_t>(g::fgrep::flags::ra);
  if(l) flag |= static_cast<uint64_t>(g::fgrep::flags::l);
  if(t) flag |= static_cast<uint64_t>(g::fgrep::flags::t);
  if(of) flag |= static_cast<uint64_t>(g::fgrep::flags::of);
  if(os) flag |= static_cast<uint64_t>(g::fgrep::flags::os);
  if(use_stdin) flag |= static_cast<uint64_t>(g::fgrep::flags::use_stdin);

  g::fgrep grep(static_cast<g::fgrep::flags>(flag), f, p, r);

  return EXIT_SUCCESS;
}
