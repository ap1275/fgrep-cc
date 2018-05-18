#pragma once

#include<list>
#include<string>
#include"def.h"

namespace g {

  class API_DEF fgrep {
  public:

    DECL_STRICT(fgrep);

    enum class flags : uint64_t {
      none = 0,
      fo = 1,
      fa = 1 << 1,
      ro = 1 << 2,
      ra = 1 << 3,
      l = 1 << 4,
      t = 1 << 5,
      of = 1 << 6,
      os = 1 << 7,
      use_stdin = 1 << 8,
    };

    fgrep(flags f, const std::list<std::string> & fpattern, const std::string & root, const std::list<std::string> & rpattern);

    void run(void(*callback)(const std::string & path, uint64_t line, const std::string & str));
  private:
    fgrep::flags flag;
  };
}
