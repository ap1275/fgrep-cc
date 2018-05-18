#pragma once

#if defined(_MSC_VER)
#define API_DEF __declspec(dllexport)
#else
#define API_DEF
#endif

// singleton
#define DECL_SINGLETON(x) \
  private: \
  x() = default; \
  ~x() = default; \
  public:\
  x(const x&) = delete; \
  x& operator=(const x&) = delete; \
  x(x&&) = delete; \
  x& operator=(x&&) = delete; \
  static x& instance() { \
    static x i; \
    return i; \
  }

// default or delete copy/move
#define DECL_COPY_MOVE(x, t) \
  x(const x&) = t; \
  x& operator=(const x&) = t; \
  x(x&&) noexcept = t; \
  x& operator=(x&&) noexcept = t

// default constructor / destructor
#define DECL_DEFAULT(x) \
  x() = default; \
  ~x() = default

#define DECL_STRICT(x) \
  DECL_COPY_MOVE(x, delete); \
  DECL_DEFAULT(x);