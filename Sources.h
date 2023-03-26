#pragma once
#include "Nodes.h"

class Source
{
private:
	double value;
	bool isCurrentSource;
	Node<double>* node1;
	Node<double>* node2;

public:
	Source(double num, Node<double>* nodeA, Node<double>* nodeB, bool CurrentSource = false)
	{
		value = num;
		node1 = nodeA;
		node2 = nodeB;
		isCurrentSource = CurrentSource;
	}

	double getValue()
	{
		return value;
	}

	Node<double>* getNode1()
	{
		return node1;
	}

	Node<double>* getNode2()
	{
		return node2;
	}

	bool getSourceType()
	{
		return isCurrentSource;
	}

	void changeNode1(Node<double>* node)
	{
		node1 = node;
	}

	void changeNode2(Node<double>* node)
	{
		node2 = node;
	}

	void changeValue(double newValue)
	{
		value = newValue;
	}

	void changeType()
	{
		isCurrentSource = !isCurrentSource;
	}
};