#ifndef ARGUMENTS_EX32_H
#define ARGUMENTS_EX32_H

#include <map>
#include <string>
#include <typeinfo>
#include <functional>

#define __ARG_VAL(key,type,obj) (*(type*)(obj.get(key)))
#define __ARG_PTR(key,type,obj) ((type*)(obj.get(key)))
#define __ARG_SET(key,value,obj) (obj.set(key,(void*)value, [&,value](void)->void{delete value;}))
#define __ARG_ASK(key,type) ([](Arguments obj)->void{\
	try{\
		type* a = new type();\
		std::cout<<key<<"(type) ";\
		std::cin>>*a;\
		obj.set(key,(void*)a,[&,a](void)->void{delete a;})\
	}catch(...){\
		std::cout<<"err";\
	}\
	std::cout<<endl;\
})



class Arguments{
	public:
		Arguments();
		~Arguments();
		void set(std::string, void*,std::function<void(void)>);
		void* get(std::string);
		void del(std::string);
	private:
		std::map<std::string, void*> args_;
		std::map<std::string, std::function<void(void)> > desreg_;
};


#endif