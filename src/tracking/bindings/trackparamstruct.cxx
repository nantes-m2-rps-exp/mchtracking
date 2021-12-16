#include <pybind11/pybind11.h>
#include "TrackBlock.h"
#include <sstream>

using o2::mch::TrackParamStruct;

namespace py = pybind11;
void init_trackparamstruct(py::module_& m) {
  py::class_<TrackParamStruct>(m, "TrackParamStruct")
      .def(py::init<double, double, double, double, double, double, short>(),
           py::arg("x") = 0.0, py::arg("y") = 0.0, py::arg("z") = 0.0,
           py::arg("px") = 0.0, py::arg("py") = 0.0, py::arg("pz") = 0.0,
           py::arg("sign") = 1)
      .def_readwrite("x", &TrackParamStruct::x)
      .def_readwrite("y", &TrackParamStruct::y)
      .def_readwrite("z", &TrackParamStruct::z)
      .def_readwrite("px", &TrackParamStruct::px)
      .def_readwrite("py", &TrackParamStruct::py)
      .def_readwrite("pz", &TrackParamStruct::pz)
      .def_readwrite("sign", &TrackParamStruct::sign)
      .def("__str__", [](const TrackParamStruct &trackParam)
           {
             std::stringstream stream;
             stream << trackParam;
             return stream.str();
           });
}