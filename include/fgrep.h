#pragma once

#include<list>
#include<string>
#include"def.h"

namespace g {

  struct API_DEF fgrep {

    DECL_STRICT(fgrep);

    enum flags : uint64_t {
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

    uint64_t flag;
    std::list<std::string> fpattern;
    std::string root;
    std::list<std::string> rpattern;

    void run(void(*callback)(const std::string & path, uint64_t line, const std::string & str));
  };
}
