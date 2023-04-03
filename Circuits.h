#pragma once
#include "Nodes.h"
#include "Resistors.h"
#include "Sources.h"
#include <vector>
#include <algorithm>

class Circuit
{
private:
	Node<double>* reference;
	std::vector<Node<double>*> nodes;
	std::vector<Resistor*> resistors;
	std::vector<Source*> sources;

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
		changed.push_back(reference);

		for (int i = 0; i < sources.size(); i++)
		{
			double temp = sources[i]->getValue() - sources[i]->getNode2()->getValue();
			sources[i]->getNode1()->changeValue(temp);
			changed.push_back(sources[i]->getNode1());
			changed.push_back(sources[i]->getNode2());
		}

		for (int i = 0; i < resistors.size(); i++)
		{
			for (int j = 0; j < resistors.size(); j++)
			{
				for (int k = 0; k < changed.size(); j++)
				{
					if ((resistors[j]->getNode1() == changed[k]) or (resistors[j]->getNode2() == changed[k]))
					{
						break;
					}
					else if (resistors[i]->getNode1() == resistors[j]->getNode1())
					{
						resistors[i]->getNode1()->changeValue(resistors[j]->getNode1()->getValue() * (resistors[i]->getResistance() / (resistors[i]->getResistance() + resistors[j]->getResistance())));
						changed.push_back(resistors[i]->getNode2());
					}
					else if (resistors[i]->getNode2() == resistors[j]->getNode1())
					{
						resistors[i]->getNode2()->changeValue(resistors[j]->getNode1()->getValue() * (resistors[i]->getResistance()/(resistors[i]->getResistance() + resistors[j]->getResistance())));
						changed.push_back(resistors[i]->getNode2());
					}
				}
			}
		}
	}
};