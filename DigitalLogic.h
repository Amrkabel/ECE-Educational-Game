#pragma once
#include "Nodes.h"
#include "Gates.h"
#include <vector>


class Logic
{
private:
	std::vector<Node<bool>*> inputs;
	std::vector<Node<bool>*> outputs;
	std::vector<Gate*> gates;
	std::vector<std::vector<bool>> truthTable;

public:
	Logic(std::vector<Node<bool>*> inp, std::vector<Node<bool>*> out, std::vector<Gate*> gate, std::vector<std::vector<bool>> table)
	{
		inputs = inp;
		outputs = out;
		truthTable = table;
		gates = gate;
	}

	void addInput(Node<bool>* x)
	{
		inputs.push_back(x);
	}

	void addOutput(Node<bool>* x)
	{
		outputs.push_back(x);
	}

	void addGate(Gate* x)
	{
		gates.push_back(x);
	}

	void changeTruthTable(std::vector<std::vector<bool>> table)
	{
		truthTable = table;
	}

	std::vector<Node<bool>*> getInputs()
	{
		return inputs;
	}

	std::vector<Node<bool>*> getOutputs()
	{
		return outputs;
	}

	/*
	* The first row in the Truth Table represents inputs and outputs, with false being inputs and true being outputs
	*/
	std::vector<std::vector<bool>> getTruthTable()
	{
		return truthTable;
	}

	/*
	* The first row in the Truth Table represents inputs and outputs, with false being inputs and true being outputs
	*/
	bool checkTruthTable()
	{
		bool check = true;

		for (int i = 1; i < truthTable.size(); i++)
		{
			for (int j = 0; j < truthTable[i].size(); j++)
			{
				if (truthTable[0][j] == false)
				{
					inputs[j]->changeValue(truthTable[i][j]);

					for (int k = 0; k < gates.size(); k++)
					{
						gates[k]->changeOutput();
					}
				}

				else 
				{
					for (int counter = 0; counter < outputs.size(); counter++)
					{
						if (outputs[counter]->getValue() != truthTable[i][j])
						{
							check = false;
							return check;
						}
					}
				}
			}
		}

		return check;
	}
};