#ifndef ARGUMENTS_EX32_H
#define ARGUMENTS_EX32_H
#import <map>
#import <string>
#define __ARG_VAL(key,type,obj) (*(*type)(obj[key]))
#define __ARG_PTR(key,type,obj) ((*type)(obj[key]))
class Arguments{
	public:
		Arguments();
		void set(std::string, void*);
		void* get(std::string);
	private:
		std::map<std::string, void*> args_;
};


#endif