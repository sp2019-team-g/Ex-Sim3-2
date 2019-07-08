#include "Arguments.h"

Arguments::Arguments(){
	args_ = std::map<std::string, void*>()
}
void Arguments::set(string key, void* value)
{
	args_[key] = value;
}

void* Arguments::get(string key){
	return args_[key];
}