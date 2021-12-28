include(FeatureSummary)
include(FetchContent)

find_package(Python COMPONENTS Interpreter Development REQUIRED)

find_package(pybind11 QUIET)
if(NOT pybind11_FOUND)
  FetchContent_Declare(pybind11
    URL https://github.com/pybind/pybind11/archive/v2.8.1.tar.gz
    URL_HASH SHA256=f1bcc07caa568eb312411dde5308b1e250bd0e1bc020fae855bf9f43209940cc)
  FetchContent_MakeAvailable(pybind11)
endif()

find_package(fmt QUIET)
if(NOT fmt_FOUND)
  FetchContent_Declare(fmt
    URL https://github.com/fmtlib/fmt/releases/download/7.1.3/fmt-7.1.3.zip
    URL_HASH SHA256=5d98c504d0205f912e22449ecdea776b78ce0bb096927334f80781e720084c9f)
  FetchContent_MakeAvailable(fmt)
endif()

find_package(FairLogger QUIET)
if(NOT FairLogger_FOUND)
  FetchContent_Declare(FairLogger
    GIT_REPOSITORY https://github.com/aphecetche/FairLogger.git
    GIT_TAG 1e5ebb9ffafe49e44a1b4d47f83e5eff18b33bfe
  )
  set(USE_EXTERNAL_FMT ON)
  FetchContent_MakeAvailable(FairLogger)
endif()

find_package(ROOT REQUIRED)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

