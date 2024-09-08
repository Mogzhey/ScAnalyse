#include "pybind11/embed.h"
#include "pybind11/numpy.h"
#include "peakfit.h"

namespace py = pybind11;

void hello(std::string text) 
{
	py::scoped_interpreter guard{};

}

