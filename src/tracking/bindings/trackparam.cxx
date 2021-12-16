#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "TrackParam.h"
#include <sstream>

using o2::mch::TrackParam;

namespace py = pybind11;
void init_trackparam(py::module_& m) {
  py::class_<TrackParam>(m, "TrackParam")
      .def(py::init<>())
      .def(py::init([](double z, std::array<double, 5> param)
                    { return std::unique_ptr<TrackParam>(new TrackParam(z, &param[0])); }))
      .def(py::init([](double z, std::array<double, 5> param,
                       std::array<double, 15> cov)
                    { return std::unique_ptr<TrackParam>(
                          new TrackParam(z, &param[0], &cov[0])); }))
      .def("__str__",
           [](const TrackParam &trackParam)
           {
             std::stringstream stream;
             stream << trackParam;
             return stream.str();
           })
      .def("getZ", &TrackParam::getZ)
      .def("setZ", &TrackParam::setZ)
      .def("getNonBendingCoor", &TrackParam::getNonBendingCoor)
      .def("setNonBendingCoor", &TrackParam::setNonBendingCoor)
      .def("getNonBendingSlope", &TrackParam::getNonBendingSlope)
      .def("setNonBendingSlope", &TrackParam::setNonBendingSlope)
      .def("getBendingCoor", &TrackParam::getBendingCoor)
      .def("setBendingCoor", &TrackParam::setBendingCoor)
      .def("getBendingSlope", &TrackParam::getBendingSlope)
      .def("setBendingSlope", &TrackParam::setBendingSlope)
      .def("getInverseBendingMomentum", &TrackParam::getInverseBendingMomentum)
      .def("setInverseBendingMomentum", &TrackParam::setInverseBendingMomentum)
      .def("getCharge", &TrackParam::getCharge)
      .def("setCharge", &TrackParam::setCharge)
      .def("px", &TrackParam::px)
      .def("py", &TrackParam::py)
      .def("pz", &TrackParam::pz)
      .def("p", &TrackParam::p)
      .def("hasCovariances", &TrackParam::hasCovariances)
      //.def("setParameters", &TrackParam::setParameters)

      .def("getParameters", [](TrackParam &self)
           {
             const auto mat = self.getParameters();
             std::vector<double> params;
             for (auto i = 0; i < mat.GetNoElements(); i++)
             {
               params.emplace_back(mat.GetMatrixArray()[i]);
             }
             return params;
           });
}