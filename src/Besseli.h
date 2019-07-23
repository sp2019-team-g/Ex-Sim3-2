
#ifndef BESSELI_EX32_H
#define BESSELI_EX32_H

#include <Python.h>
#include <utility>
#include <complex>
#include <iostream>
namespace BSI
{
	void PYB();
	std::complex<double> I_(PyObject*, PyObject*);
	std::complex<double> I(std::complex<double>, std::complex<double>);
	std::complex<double> I(std::complex<double>, double);
	std::complex<double> I(double, std::complex<double>);
	std::complex<double> I(double, double);
	void PYE();
}

#endif
