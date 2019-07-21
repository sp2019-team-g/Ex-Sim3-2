#ifndef ARGUMENTS_EX32_H
#define ARGUMENTS_EX32_H

#include <map>
#include <string>
#include <typeinfo>
#include <functional>

#include <iostream>
// #define __ARG_VAL(key,type,obj) (*(type*)(obj.get(key)))
// #define __ARG_PTR(key,type,obj) ((type*)(obj.get(key)))
// #define __ARG_SET(key,value,obj) (obj.set(key,(void*)value, [&,value](void)->void{delete value;}))
// #define __ARG_ASK(key,type) ([](Arguments obj)->void{\
// 	try{\
// 		type* a = new type();\
// 		std::cout<<key<<"("<<#type<<") ";\
// 		std::cin>>*a;\
// 		obj.set(key,(void*)a,[&,a](void)->void{delete a;});\
// 	}catch(...){\
// 		std::cout<<"err";\
// 	}\
// 	std::cout<<std::endl;\
// })



class Arguments{
	public:
		Arguments();
		~Arguments();
		void set(std::string, void*,std::function<void(void)>);
		void* get(std::string);
		void del(std::string);
		template<class T> T g_VAL(std::string key)
		{
			return (*(T*)(get(key)));
		}
		template<class T> T* g_PTR(std::string key)
		{
			return (T*)get(key);
		}
		template<class T>void g_SET(std::string key,T*val)
		{
			set(key,(void*)val,[&,val](void)->void{delete val;});
		}
		// template<class T> T g_VAL(std::string);
		// template<class T> T* g_PTR(std::string);
		// template<class T> void g_SET(std::string,T*);
		// template<class T> friend std::function<void(Arguments)> g_ASK(std::string, T*);
	private:
		std::map<std::string, void*> args_;
		std::map<std::string, std::function<void(void)> > desreg_;
};
template<class T> std::function<void(Arguments&)> g_ASK(std::string key)
{
	T* a = new T();
	std::cout<<a<<std::endl;
	return [&,key,a](Arguments& arg)->void
	{
		std::cout<<key<<" : ";
		try
		{
			std::cin>>*a;
			arg.g_SET<T>(key,a);
		}
		catch(...)
		{
			std::cout<<"err";
		}
		std::cout<<arg.g_VAL<T>(key);
		std::cout<<std::endl;
	};
}


#endif