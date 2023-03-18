#pragma once
#include <string>

template <class T>
class Node
{
private:
	T value;
	string name;

public:
	Node Node(T initial)
	{
		value = initial;

		return this;
	}

	Node Node(T initial, string nodeName)
	{
		value = initial;
		name = nodeName;

		return this;
	}

	T getValue()
	{
		return value;
	}

	string getName()
	{
		return name;
	}
};