#include <pybind11/pybind11.h>
#include "TrackExtrap.h"
#include "TrackParam.h"

using o2::mch::TrackExtrap;

namespace py = pybind11;
void init_trackextrap(py::module_ &m)
{
	py::class_<TrackExtrap, std::unique_ptr<TrackExtrap, py::nodelete>>(
	    m, "TrackExtrap")

	    .def_static("setField", []()
			{ TrackExtrap::setField(); })
	    .def("extrapToZ", &TrackExtrap::extrapToZ);
}