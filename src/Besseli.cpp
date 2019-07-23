
#include "Besseli.h"

bool stdd = false;
PyObject* mname;
PyObject* mpmath;
PyObject* besseli;

void BSI::PYB()
{
	if(!stdd)
	{
		Py_Initialize();
		stdd = true;
		mname = PyUnicode_FromString("mpmath");
		mpmath = PyImport_Import(mname);
		besseli = PyObject_GetAttrString(mpmath, "besseli");
	}
}

std::complex<double> BSI::I_(PyObject* V, PyObject* X)
{
	PyObject* args = PyTuple_Pack(2, V, X);
	PyObject* res = PyObject_CallObject(besseli, args);
	PyObject* z = PyObject_GetAttrString(res, "__complex__");
	PyObject* rres = PyObject_CallObject(z, NULL);
	return std::complex<double>(PyComplex_RealAsDouble(rres),PyComplex_ImagAsDouble(rres));
}


std::complex<double> BSI::I(std::complex<double> v, std::complex<double> x)
{
	if(!stdd)
	{
		std::cout<<"py not started"<<std::endl;
	}
	PyObject* V = PyComplex_FromDoubles(std::real(v),std::imag(v));
	PyObject* X = PyComplex_FromDoubles(std::real(x),std::imag(v));
	return BSI::I_(V,X);
}

std::complex<double> BSI::I(std::complex<double> v, double x)
{
	if(!stdd)
	{
		std::cout<<"py not started"<<std::endl;
	}
	PyObject* V = PyComplex_FromDoubles(std::real(v),std::imag(v));
	PyObject* X = PyComplex_FromDoubles(x,0.0);
	return BSI::I_(V,X);	
}

std::complex<double> BSI::I(double v, std::complex<double> x)
{
	if(!stdd)
	{
		std::cout<<"py not started"<<std::endl;
	}
	PyObject* V = PyComplex_FromDoubles(v, 0.0);
	PyObject* X = PyComplex_FromDoubles(std::real(x), std::imag(x));
	return BSI::I_(V,X);	
}

std::complex<double> BSI::I(double v, double x)
{
	if(!stdd)
	{
		std::cout<<"py not started"<<std::endl;
	}
	PyObject* V = PyComplex_FromDoubles(v,0.0);
	PyObject* X = PyComplex_FromDoubles(x,0.0);
	return BSI::I_(V,X);
}

void BSI::PYE()
{
	if(stdd)
	{
		Py_Finalize();
		stdd = false;
	}

}
