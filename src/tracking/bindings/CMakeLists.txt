pybind11_add_module(mchtracking SHARED
  python-bindings.cxx
  cluster.cxx
  trackextrap.cxx
  trackfitter.cxx
  trackparam.cxx
  trackparamstruct.cxx
  THIN_LTO)

target_link_libraries(mchtracking PUBLIC o2tracking)

# Support for running from build directory
file(WRITE "${PROJECT_BINARY_DIR}/pytest.ini" "[pytest]\n"
                                              "testpaths = ${CMAKE_CURRENT_SOURCE_DIR}\n")

# Support plain "pytest" in addition to "python -m pytest"
file(WRITE "${PROJECT_BINARY_DIR}/conftest.py" "import sys\n"
                                               "sys.path.insert(0, '${PROJECT_BINARY_DIR}')\n")

# Look for all the tests
file(GLOB MCHTRACKING_PY_TESTS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test_*.py")

# Add each test
foreach(TEST_FILE IN LISTS MCHTRACKING_PY_TESTS)
  get_filename_component(TEST_NAME "${TEST_FILE}" NAME_WE)
  add_test(
        NAME ${TEST_NAME}
        COMMAND ${Python_EXECUTABLE} -m pytest "${TEST_FILE}" --rootdir=.
        WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")
  set_tests_properties(${TEST_NAME} PROPERTIES LABELS python)
endforeach()

if(NOT TARGET check)
  add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
endif()

install(TARGETS mchtracking LIBRARY DESTINATION lib/python${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}/site-packages)
