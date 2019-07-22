#ifndef ARGUMENTS_EX32_H
#define ARGUMENTS_EX32_H

#include <map>
#include <string>
#include <typeinfo>
#include <functional>
#include <iostream>




class Arguments{
	public:
		Arguments();
		~Arguments();
		void set(std::string, void*, std::function<void(void)>);
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
		template<class T> void g_SET(std::string key,T*val)
		{
			set(key,(void*)val,[&,val](void)->void{delete val;});
		}

	private:
		std::map<std::string, void*> args_;
		std::map<std::string, std::function<void(void)> > desreg_;
};

template<class T> std::function<void(Arguments&)> g_ASK(std::string key)
{
	T* a = new T();
	return [&,key,a](Arguments& arg)->void
	{
		std::cout<<key<<"("<<typeid(T).name() <<") : ";
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

typedef std::vector<std::function<void(Arguments&)> > PLIST;


#endif