#include "Besseli.h"
std::pair<double, double> BSI::I(std::pair<double, double>v, std::pair<double, double>x)
{
	Py_Initialize();
	Py_Initialize();
	PyObject* V = PyComplex_FromDoubles(v.first,v.second);
	PyObject* X = PyComplex_FromDoubles(x.first,x.second);
	PyObject* mpmath = PyUnicode_FromString("mpmath");
	PyObject* Mpmath = PyImport_Import(mpmath);
	PyObject* besseli = PyObject_GetAttrString(Mpmath,"besseli");
	PyObject* args = PyTuple_Pack(2, V, X);
	PyObject* res = PyObject_CallObject(besseli, args);

	PyObject* z = PyObject_GetAttrString(res,"__complex__");

	PyObject* rres = PyObject_CallObject(z, NULL); 

	std::pair<double,double> r;

	r.first = PyComplex_RealAsDouble(rres);
	r.second = PyComplex_ImagAsDouble(rres);
	Py_Finalize();
	return r;
}