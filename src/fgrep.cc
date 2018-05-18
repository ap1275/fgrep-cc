#include<internal_fgrep.h>
#include<iostream>

g::fgrep::fgrep(flags f, const std::list<std::string> & fpattern, const std::string & root, const std::list<std::string> & rpattern) : flag(f) {

}

void g::fgrep::run(void(*callback)(const std::string & path, uint64_t line, const std::string & str)) {

}
