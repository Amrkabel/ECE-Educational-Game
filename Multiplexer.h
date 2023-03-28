#pragma once
#include "Nodes.h"

class Mux4
{
private:
	Node<bool>* S0;
	Node<bool>* S1;
	Node<bool>* input1;
	Node<bool>* input2;
	Node<bool>* input3;
	Node<bool>* input4;
	Node<bool>* output;

public:
	Mux4(Node<bool>* Select0, Node<bool>* Select1, Node<bool>* inp1, Node<bool>* inp2, Node<bool>* inp3, Node<bool>* inp4, Node<bool>* out)
	{
		S0 = Select0;
		S1 = Select1;
		input1 = inp1;
		input2 = inp2;
		input3 = inp3;
		input4 = inp4;
		output = out;
	}

	Node<bool>* getOutput()
	{
		return output;
	}

	Node<bool>* getInput1()
	{
		return input1;
	}

	Node<bool>* getInput2()
	{
		return input2;
	}

	Node<bool>* getInput3()
	{
		return input3;
	}

	Node<bool>* getInput4()
	{
		return input4;
	}

	Node<bool>* getSelect0()
	{
		return S0;
	}

	Node<bool>* getSelect1()
	{
		return S1;
	}

	void changeOutput()
	{
		bool x;
		if ((S0->getValue() == false) and (S1->getValue() == false))
		{
			x = input1->getValue();
		}

		else if ((S0->getValue() == false) and (S1->getValue() == true))
		{
			x = input2->getValue();
		}

		else if ((S0->getValue() == true) and (S1->getValue() == false))
		{
			x = input3->getValue();
		}

		else if ((S0->getValue() == true) and (S1->getValue() == true))
		{
			x = input4->getValue();
		}

		output->changeValue(x);
	}
};