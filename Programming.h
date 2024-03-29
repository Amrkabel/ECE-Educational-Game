#pragma once
#include <string>
#include <vector>

class Programming
{
private:
	std::string code;
	std::vector<int> errors;

public:
	Programming(std::string c, std::vector<int> e)
	{
		code = c;
		errors = e;
	}

	void addError(int error)
	{
		errors.push_back(error);
	}

	void changeCode(std::string c)
	{
		code = c;
	}

	void changeErrors(std::vector<int> e)
	{
		errors = e;
	}

	std::string getCode()
	{
		return code;
	}

	std::vector<int> getErrors()
	{
		return errors;
	}
	
	bool result(std::vector<int> user_input){
		std::sort(user_input.begin(), user_input.end());
		std::sort(errors.begin(), errors.end());
		return user_input == errors;
	}
};
