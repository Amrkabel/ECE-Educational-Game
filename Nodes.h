#pragma once
#include <string>

template <class T>
class Node
{
private:
	T value;
	std::string name;

public:
	Node(T initial = 0, std::string nodeName = "")
	{
		value = initial;
		name = nodeName;
	}

	T getValue()
	{
		return value;
	}

	std::string getName()
	{
		return name;
	}

	void changeValue(T newValue)
	{
		value = newValue;
	}

	void changeName(std::string newName)
	{
		name = newName;
	}
};