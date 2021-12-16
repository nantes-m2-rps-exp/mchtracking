
#include "TrackParam.h"
#include "TrackFitter.h"
#include "Cluster.h"
#include <pybind11/pybind11.h>

using namespace pybind11::literals;
namespace py = pybind11;
using namespace o2::mch;

#include <iostream>

void init_trackfitter(py::module &m)
{
	py::class_<TrackFitter>(m, "TrackFitter")
	    .def(py::init<>())
	    .def(
		"initTrack", [](TrackFitter &trackFitter, Cluster c1, Cluster c2)
		{
			TrackParam tp;
			trackFitter.initTrack(c1, c2, tp);
			return tp;
		},
		py::arg("c1"), py::arg("c2"));
}