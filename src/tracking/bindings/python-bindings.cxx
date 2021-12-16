#include <pybind11/pybind11.h>
#include <sstream>
#include "TrackFitter.h"
#include "TrackExtrap.h"

namespace py = pybind11;

void init_cluster(py::module_ &);
void init_trackextrap(py::module_ &);
void init_trackfitter(py::module_ &);
void init_trackparam(py::module_ &);
void init_trackparamstruct(py::module_ &);

PYBIND11_MODULE(mchtracking, m)
{
  m.doc() = "Python interface to MCH Tracking O2 Library";

  init_cluster(m);
  init_trackextrap(m);
  init_trackfitter(m);
  init_trackparam(m);
  init_trackparamstruct(m);

  m.def(
      "initField", [](float l3Current, float dipoleCurrent)
      {
        o2::mch::TrackFitter tf;
        tf.initField(l3Current, dipoleCurrent);
      },
      py::arg("l3Current") = static_cast<float>(30000), py::arg("dipoleCurrent") = static_cast<float>(6000));

  m.def("isFieldON", []()
        { return o2::mch::TrackExtrap::isFieldON(); });
}
