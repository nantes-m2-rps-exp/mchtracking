include(FeatureSummary)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
find_package(FairLogger REQUIRED)
find_package(ROOT REQUIRED)
find_package(fmt REQUIRED)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

