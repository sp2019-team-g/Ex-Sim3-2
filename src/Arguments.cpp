#include "Arguments.h"

Arguments::Arguments()
{
	args_ = std::map<std::string, void*>();
	desreg_ = std::map<std::string, std::function<void(void)> >();
}

Arguments::~Arguments()
{
	for(
		std::map<std::string,std::function<void(void)> >::iterator it = desreg_.begin();
		it != desreg_.end();
		it++
		)
		(it->second)();

}

void Arguments::set(std::string key, void* value, std::function<void(void)>des)
{
	if(args_.find(key) == args_.end())
	{
		args_[key] = value;
		desreg_[key] = des;
	}
	else
	{
		del(key);
		args_[key] = value;
		desreg_[key] = des;
	}
}

void* Arguments::get(std::string key)
{
	return args_[key];
}

void Arguments::del(std::string key)
{
	desreg_[key]();
}

// template<class T> T Arguments::g_VAL(std::string key)
// {
// 	return (*(T*)(get(key)));
// }

// template<class T> T* Arguments::g_PTR(std::string key)
// {
// 	return (T*)get(key);
// }

// template<class T>void Arguments::g_SET(std::string key,T*val)
// {
// 	set(key,(void*)val,[&,val](void)->void{delete val;});
// }

// template<class T> std::function<void(Arguments)> g_ASK(std::string key)
// {
// 	return [&,key](Arguments arg)->void
// 	{
// 		T a;
// 		std::cout<<key<<" : ";
// 		try{
// 			std::cin>>a;
// 			arg.g_SET(key,new T(a));
// 		}
// 		catch(...)
// 		{
// 			std::cout<<"err";
// 		}
// 		std::cout<<std::endl;
// 	};
// }

