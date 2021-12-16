#include "MagneticField.h"
#include <cstdlib>
#include <fmt/core.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>
using namespace pybind11::literals;
namespace py = pybind11;
using namespace o2::field;

#include <iostream>

void toto() { std::cout << "toto\n"; }
PYBIND11_MODULE(mchfield, m) {
  m.doc() = "mchfield plugin";

  m.def("toto", &toto, "A function which prints toto");

  py::class_<MagneticField, std::unique_ptr<MagneticField, py::nodelete>>(
      m, "MagneticField")
      .def_static(
          "createFieldMap",
          [](float l3Current, float diCurrent, int convention, bool uniform,
             float beamenergy, const std::string btype,
             const std::string path) {
            return MagneticField::createFieldMap(
                l3Current, diCurrent, convention, uniform, beamenergy,
                btype.c_str(), path);
          },

          py::arg("l3Current") = -30000.0, py::arg("diCurrent") = -6000.0,
          py::arg("convention") = 0, py::arg("uniform") = false,
          py::arg("beamenergy") = 7000, py::arg("btype") = "pp",
          py::arg("path") = fmt::format(
              "{}/share/Common/maps/mfchebKGI_sym.root", std::getenv("O2_ROOT"))

              )
      .def("solenoidField", &MagneticField::solenoidField)

      ;
}
