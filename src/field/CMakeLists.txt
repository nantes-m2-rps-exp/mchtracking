add_library(o2field SHARED)

target_sources(o2field PRIVATE
  Chebyshev3D.cxx
  Chebyshev3DCalc.cxx
  MagFieldFast.cxx
  MagFieldParam.cxx
  MagneticField.cxx
  MagneticWrapperChebyshev.cxx
)

target_include_directories(o2field
    PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)


root_generate_dictionary(G__o2field
  MagneticField.h
  MagneticWrapperChebyshev.h
  MagFieldFast.h
  Chebyshev3D.h
  Chebyshev3DCalc.h
                         field-linkdef.h
  MODULE o2field)
target_link_libraries(o2field PUBLIC FairLogger::FairLogger ROOT::Geom)

add_executable(test-magnetic-field testMagneticField.cxx)
target_link_libraries(test-magnetic-field PRIVATE Boost::unit_test_framework
o2field)

add_test(NAME testMagneticField COMMAND test-magnetic-field)
set_tests_properties(testMagneticField PROPERTIES ENVIRONMENT O2_ROOT=${CMAKE_BINARY_DIR}/stage)

install(DIRECTORY maps DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/Common)

file(COPY maps DESTINATION ${CMAKE_BINARY_DIR}/stage/${CMAKE_INSTALL_DATAROOTDIR}/Common)

install(TARGETS o2field)

if(BUILD_PYTHON_BINDINGS)
  add_subdirectory(bindings)
endif()
