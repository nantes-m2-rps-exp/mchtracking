#include <pybind11/pybind11.h>
#include "Cluster.h"
#include <sstream>

using o2::mch::Cluster;

namespace py = pybind11;

void init_cluster(py::module_& m) {
  py::class_<Cluster>(m, "Cluster")
      .def(py::init<float, float, float, float, float, uint32_t, uint32_t,
                    uint32_t>(),
           py::arg("x") = 0.0f, py::arg("y") = 0.0f, py::arg("z") = 0.0f,
           py::arg("ex") = 0.0f, py::arg("ey") = 0.0f, py::arg("uid") = 0,
           py::arg("firstDigit") = 0, py::arg("nDigits") = 0)
      .def("getX", &Cluster::getX)
      .def("getY", &Cluster::getY)
      .def("getZ", &Cluster::getZ)
      .def("getEx", &Cluster::getEx)
      .def("getEy", &Cluster::getEy)
      .def("getEx2", &Cluster::getEx2)
      .def("getEy2", &Cluster::getEy2)
      .def("getIdAsString", &Cluster::getIdAsString)
      .def("getDEId",
           [](const Cluster &cluster)
           { return cluster.getDEId(cluster.uid); })
      .def("getClusterIndex",
           [](const Cluster &cluster)
           {
             return cluster.getClusterIndex(cluster.uid);
           })
      .def("getChamberId",
           [](const Cluster &cluster)
           {
             return cluster.getChamberId(cluster.uid);
           })
      .def_static(
          "buildUniqueId",
          [](int chamberId, int deId, int clusterIndex)
          {
            return Cluster::buildUniqueId(chamberId, deId, clusterIndex);
          },
          py::arg("chamberId"), py::arg("deId"), py::arg("clusterIndex"))
      .def("__str__", [](const Cluster &cluster)
           {
             std::stringstream stream;
             stream << cluster;
             return stream.str();
           });
}