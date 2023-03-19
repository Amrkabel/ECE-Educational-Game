#pragma once
#include "Nodes.h"
#include <string>

class Gate
{
private:
	std::string type;
	Node<bool>* input1;
	Node<bool>* input2;
	Node<bool>* output;

public:
	Gate(std::string typ, Node<bool>* inp1, Node<bool>* inp2, Node<bool>* out)
	{
		type = typ;
		input1 = inp1;
		input2 = inp2;
		output = changeOutput();
	}

	void changeType(std::string typ)
	{
		type = typ;
		output = changeOutput();
	}

	Node<bool>* changeOutput()
	{
		if (type == "and")
		{
			return andGate();
		}

		else if (type == "or")
		{
			return orGate();
		}

		else if (type == "xor")
		{
			return xorGate();
		}

		else if (type == "nand")
		{
			return nandGate();
		}

		else if (type == "nor")
		{
			return norGate();
		}

		else if (type == "xnor")
		{
			return xnorGate();
		}

		else if (type == "not")
		{
			return notGate();
		}
	}

	Node<bool>* andGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = x and y;
		output->changeValue(value);
	}

	Node<bool>* orGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = x or y;
		output->changeValue(value);
	}

	Node<bool>* xorGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = x ^ y;
		output->changeValue(value);
	}

	Node<bool>* nandGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = !(x and y);
		output->changeValue(value);
	}

	Node<bool>* norGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = !(x or y);
		output->changeValue(value);
	}

	Node<bool>* xnorGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = !(x ^ y);
		output->changeValue(value);
	}

	Node<bool>* notGate()
	{
		bool x = input1->getValue();
		bool value = !(x);
		output->changeValue(value);
	}

	void changeInputOne(Node<bool>* inp1)
	{
		input1 = inp1;
		output = changeOutput();
	}

	void changeInputTwo(Node<bool>* inp2)
	{
		input2 = inp2;
		output = changeOutput();
	}

	Node<bool>* getInputOne()
	{
		return input1;
	}

	Node<bool>* getInputTwo()
	{
		return input2;
	}

	Node<bool>* getOutput()
	{
		return output;
	}

	std::string getType()
	{
		return type;
	}
};