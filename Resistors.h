#pragma once
#include "Nodes.h"

class Resistor
{
private:
	double value;
	Node<double>* node1;
	Node<double>* node2;

public:
	Resistor(double resistance, Node<double>* nodeA, Node<double>* nodeB)
	{
		value = resistance;
		node1 = nodeA;
		node2 = nodeB;
	}

	double getCurrent()
	{
		double current = abs(node1->getValue() - node2->getValue()) / value;
		return current;
	}

	void changeResistance(double resistance)
	{
		value = resistance;
	}

	void changeNode1(Node<double>* node)
	{
		node1 = node;
	}

	void changeNode2(Node<double>* node)
	{
		node2 = node;
	}

	double getResistance()
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
};