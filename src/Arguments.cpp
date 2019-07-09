#include "Arguments.h"

Arguments::Arguments()
{
	args_ = std::map<std::string, void*>();
}

void Arguments::set(std::string key, void* value)
{
	if(args_.find(key) == args_.end())
	{
		args_[key] = value;
	}
	else
	{
		//delete args_[key];
		//free
		args_[key] = value;
	}
}

void* Arguments::get(std::string key)
{
	return args_[key];
}