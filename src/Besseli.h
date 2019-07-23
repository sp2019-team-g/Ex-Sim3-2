
#ifndef BESSELI_EX32_H
#define BESSELI_EX32_H

#include <Python.h>
#include <utility>
#include <complex>
#include <iostream>
namespace BSI
{
	#ifndef P__MAIN__
	bool stdd = false;
	PyObject* mname;
	PyObject* mpmath;
	PyObject* besseli;
	#endif
	void PYB();
	// std::pair<double, double> I(std::pair<double, double>, std::pair<double, double>);
	std::complex<double> I_(PyObject*, PyObject*);
	std::complex<double> I(std::complex<double>, std::complex<double>);
	std::complex<double> I(std::complex<double>, double);
	std::complex<double> I(double, std::complex<double>);
	std::complex<double> I(double, double);
	void PYE();
}

#endif
