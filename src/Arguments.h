#ifndef ARGUMENTS_EX32_H
#define ARGUMENTS_EX32_H

#include <map>
#include <string>
#include <typeinfo>
#include <functional>
#include <iostream>
#include <vector>
#include <limits>


class Arguments{
	public:
		Arguments();
		~Arguments();


		bool has(std::string);
		template<class T> T g_VAL(std::string key)
		{
			return (*(T*)(get(key)));
		}
		template<class T> T* g_PTR(std::string key)
		{
			return (T*)get(key);
		}
		template<class T> void g_SET(std::string key, T*val)
		{
			set(key,(void*)val,[&,val](void)->void{delete val;});
		}

	private:
		void set(std::string, void*, std::function<void(void)>);
		void* get(std::string);
		void del(std::string);
		std::map<std::string, void*> args_;
		std::map<std::string, std::function<void(void)> > desreg_;
};

template<class T> std::function<void(Arguments&)> g_ASK(std::string key)
{

	T* a = new T();
	return [&,key,a](Arguments& arg)->void
	{
		if(arg.has(key))
		{
			delete a;
			return;
		}
		while(1)
		{
			std::cout<<key<<"("<<typeid(T).name() <<") : ";

			std::cin>>*a;

			if(std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				std::cout<<"err"<<std::endl;
			}
			else
			{
				arg.g_SET<T>(key,a);
				break;
			}
		}
	};
}

typedef std::vector<std::function<void(Arguments&)> > PLIST;


#endif