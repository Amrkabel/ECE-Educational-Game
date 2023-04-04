#pragma once
#include "Nodes.h"
#include "Resistors.h"
#include "Sources.h"
#include <vector>
#include <iostream>

class Circuit
{
private:
	Node<double>* reference;
	std::vector<Node<double>*> nodes;
	std::vector<Resistor*> resistors;
	std::vector<Source*> sources;
	Resistor* net;

public:
	Circuit(Node<double>* ref, std::vector<Node<double>*> node, std::vector<Resistor*> res, std::vector<Source*> source)
	{
		reference = ref;
		nodes = node;
		resistors = res;
		sources = source;
		changeValues();
	}

	//Assume Source is a Voltage Source. Current source implementation TBA
	void changeValues()
	{
		reference->changeValue(0);
		std::vector<Node<double>*> changed;

		for (int i = 0; i < sources.size(); i++)
		{
			if (sources[i]->getNode1() != reference)
			{
				double temp = sources[i]->getValue() - sources[i]->getNode2()->getValue();
				sources[i]->getNode1()->changeValue(temp);
				changed.push_back(sources[i]->getNode1());
				changed.push_back(sources[i]->getNode2());
			}

			else
			{
				double temp = sources[i]->getValue() - sources[i]->getNode1()->getValue();
				sources[i]->getNode2()->changeValue(temp);
				changed.push_back(sources[i]->getNode1());
				changed.push_back(sources[i]->getNode2());
			}
		}

		double val = changeResistor(1);

		Resistor n(val, sources[0]->getNode1(), reference);

		net = &n;
	}

	double changeResistor(int i)
	{
		double val = 0;

		if (resistors[i]->getNode1() == resistors[i - 1]->getNode1())
		{
			if (resistors[i]->getNode2() == resistors[i - 1]->getNode2())
			{
				val += 1 / ((1 / resistors[i]->getResistance()) + (1 / resistors[i - 1]->getResistance()));
			}

			else
			{
				double newval = changeResistor(i + 1);
				val += 1 / ((1 / resistors[i]->getResistance()) + (1 / newval));
			}
		}

		else if (resistors[i - 1]->getNode2() == resistors[i]->getNode1())
		{
			if (i == (resistors.size() - 1))
			{
				val += resistors[i]->getResistance() + resistors[i - 1]->getResistance();
			}

			else if (resistors[i]->getNode2() == resistors[i + 1]->getNode1())
			{
				val += resistors[i]->getResistance() + resistors[i - 1]->getResistance();
			}

			else
			{
				val += changeResistor(i + 1) + resistors[i - 1]->getResistance();
			}
		}

		std::cout << val << std::endl;
		return val;
	}

	double getCurrent()
	{
		return net->getCurrent();
	}
};