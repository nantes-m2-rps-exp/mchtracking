add_library(o2tracking SHARED)

target_sources(o2tracking PUBLIC
  Cluster.cxx
  Track.cxx
  TrackBlock.cxx
  TrackExtrap.cxx
  TrackFitter.cxx
  TrackParam.cxx
)

target_include_directories(o2tracking
    PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(o2tracking PUBLIC ROOT::Geom ROOT::MathMore FairLogger::FairLogger o2field)

install(TARGETS o2tracking)

if(BUILD_PYTHON_BINDINGS)
  add_subdirectory(bindings)
endif()
