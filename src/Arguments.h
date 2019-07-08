#ifndef ARGUMENTS_EX32_H
#define ARGUMENTS_EX32_H
#import <map>
#import <string>
class Arguments{
	public:
		Arguments();
		void set(std::string, void*);
		void* get(std::string);
	private:
		std::map<std::string, void*> args_;
};


#endif