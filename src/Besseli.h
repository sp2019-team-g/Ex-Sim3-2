#include <Python.h>
#include <utility>
#include <complex>
#include <iostream>
namespace BSI{
	bool stdd = false;
	PyObject* mname;
	PyObject* mpmath;
	PyObject* besseli;
	void PYB();
	// std::pair<double, double> I(std::pair<double, double>, std::pair<double, double>);
	std::complex<double> I_(PyObject*, PyObject*);
	std::complex<double> I(std::complex<double>, std::complex<double>);
	std::complex<double> I(std::complex<double>, double);
	std::complex<double> I(double, std::complex<double>);
	std::complex<double> I(double, double);
	void PYE();
};