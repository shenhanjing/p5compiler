#pragma once

// Minimal config for standalone p5compiler build.
// Disable optional deps to reduce linkage requirements.
#define HAVE_LIBBOOST_IOSTREAMS 0
#define HAVE_LIBBOOST_GRAPH 0
#define HAVE_LIBBACKTRACE 0
#define HAVE_LIBGC 0
#define HAVE_LIBGMP 0
#define HAVE_UCONTEXT_H 1
#define HAVE_CXXABI_H 1
#define HAVE_MM_MALLOC_H 0

#define CONFIG_PKGDATADIR "/usr/local/share/p4c"
#define CONFIG_PREFIX "/usr/local"
#define MAX_LOGGING_LEVEL 10

// No gtest in standalone tool. Intentionally do NOT define P4C_GTEST_ENABLED,
// because some headers use `#ifdef P4C_GTEST_ENABLED`.
