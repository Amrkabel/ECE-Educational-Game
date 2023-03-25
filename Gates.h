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
		output = out;
		changeOutput();
	}

	void changeType(std::string typ)
	{
		type = typ;
		changeOutput();
	}

	void changeOutput()
	{
		if (type == "and")
		{
			andGate();
		}

		else if (type == "or")
		{
			orGate();
		}

		else if (type == "xor")
		{
			xorGate();
		}

		else if (type == "nand")
		{
			nandGate();
		}

		else if (type == "nor")
		{
			norGate();
		}

		else if (type == "xnor")
		{
			xnorGate();
		}

		else if (type == "not")
		{
			notGate();
		}
	}

	void andGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = x and y;
		output->changeValue(value);
	}

	void orGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = x or y;
		output->changeValue(value);
	}

	void xorGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = x ^ y;
		output->changeValue(value);
	}

	void nandGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = !(x and y);
		output->changeValue(value);
	}

	void norGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = !(x or y);
		output->changeValue(value);
	}

	void xnorGate()
	{
		bool x = input1->getValue();
		bool y = input2->getValue();
		bool value = !(x ^ y);
		output->changeValue(value);
	}

	void notGate()
	{
		bool x = input1->getValue();
		bool value = !(x);
		output->changeValue(value);
	}

	void changeInputOne(Node<bool>* inp1)
	{
		input1 = inp1;
		changeOutput();
	}

	void changeInputTwo(Node<bool>* inp2)
	{
		input2 = inp2;
		changeOutput();
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

	void changeInputOneValue(bool x)
	{
		input1->changeValue(x);
		changeOutput();
	}

	void changeInputTwoValue(bool x)
	{
		input1->changeValue(x);
		changeOutput();
	}
};