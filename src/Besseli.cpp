#include "Besseli.h"
void BSI::PYB(){
	if(!BSI::stdd){
		Py_Initialize();
		BSI::stdd = true;
		BSI::mname = PyUnicode_FromString("mpmath");
		BSI::mpmath = PyImport_Import(BSI::mname);
		BSI::besseli = PyObject_GetAttrString(BSI::mpmath,"besseli");
	}
}
// std::pair<double, double> BSI::I(std::pair<double, double>v, std::pair<double, double>x)
// {
// 	if(!BSI::stdd){
// 		cout<<"py not started"<<endl;
// 	}
// 	PyObject* V = PyComplex_FromDoubles(v.first,v.second);
// 	PyObject* X = PyComplex_FromDoubles(x.first,x.second);

// 	PyObject* args = PyTuple_Pack(2, V, X);
// 	PyObject* res = PyObject_CallObject(BSI::besseli, args);

// 	PyObject* z = PyObject_GetAttrString(res, "__complex__");

// 	PyObject* rres = PyObject_CallObject(z, NULL); 

// 	std::pair<double,double> r;

// 	r.first = PyComplex_RealAsDouble(rres);
// 	r.second = PyComplex_ImagAsDouble(rres);
// 	return r;
// }

std::complex<double> BSI::I_(PyObject* V, PyObject* X)
{
	PyObject* args = PyTuple_Pack(2, V, X);
	PyObject* res = PyObject_CallObject(BSI::besseli, args);
	PyObject* z = PyObject_GetAttrString(res, "__complex__");
	PyObject* rres = PyObject_CallObject(z, NULL);
	return std::complex<double>(PyComplex_RealAsDouble(rres),PyComplex_ImagAsDouble(rres));
}


std::complex<double> BSI::I(std::complex<double> v, std::complex<double> x)
{
	if(!BSI::stdd)
	{
		std::cout<<"py not started"<<std::endl;
	}
	PyObject* V = PyComplex_FromDoubles(std::real(v),std::imag(v));
	PyObject* X = PyComplex_FromDoubles(std::real(x),std::imag(v));
	return BSI::I_(V,X);
}

std::complex<double> BSI::I(std::complex<double> v, double x)
{
	if(!BSI::stdd)
	{
		std::cout<<"py not started"<<std::endl;
	}
	PyObject* V = PyComplex_FromDoubles(std::real(v),std::imag(v));
	PyObject* X = PyComplex_FromDoubles(x,0.0);
	return BSI::I_(V,X);	
}

std::complex<double> BSI::I(double v, std::complex<double> x)
{
	if(!BSI::stdd)
	{
		std::cout<<"py not started"<<std::endl;
	}
	PyObject* V = PyComplex_FromDoubles(v, 0.0);
	PyObject* X = PyComplex_FromDoubles(std::real(x), std::imag(x));
	return BSI::I_(V,X);	
}

std::complex<double> BSI::I(double v, double x)
{
	if(!BSI::stdd)
	{
		std::cout<<"py not started"<<std::endl;
	}
	PyObject* V = PyComplex_FromDoubles(v,0.0);
	PyObject* X = PyComplex_FromDoubles(x,0.0);
	return BSI::I_(V,X);
}

void PYE()
{
	if(BSI::stdd)
	{
		Py_Finalize();
		BSI::stdd = false;
	}

}