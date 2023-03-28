#include <iostream>
#include "Nodes.h"
#include "Gates.h"
#include "DigitalLogic.h"
#include <vector>

bool result_Logic(std::string gate1, std::string gate2)
{
	std::string x = "A";
	Node<bool> nodeA(false, x);
	x = "B";
	Node<bool> nodeB(false, x);
	x = "C";
	Node<bool> nodeC(false, x);
	x = "D";
	Node<bool> interimNode(true, x);
	x = "F";
	Node<bool> output(true, x);

	x = gate1;
	Gate gate_and(x, &nodeA, &nodeB, &interimNode);

	Node<bool>* nodeD = gate_and.getOutput();

	x = gate2;
	Gate gate_or(x, nodeD, &nodeC, &output);

	std::vector<Node<bool>*> inputs;
	std::vector<Node<bool>*> outputs;
	std::vector<Gate*> Bill_Gates;
	std::vector<std::vector<bool>> table(9, std::vector<bool>(4));

	table[0][0] = false;
	table[0][1] = false;
	table[0][2] = false;
	table[0][3] = true;

	table[1][0] = false;
	table[2][0] = false;
	table[3][0] = false;
	table[4][0] = false;
	table[5][0] = true;
	table[6][0] = true;
	table[7][0] = true;
	table[8][0] = true;

	table[1][1] = false;
	table[2][1] = false;
	table[3][1] = true;
	table[4][1] = true;
	table[5][1] = false;
	table[6][1] = false;
	table[7][1] = true;
	table[8][1] = true;

	table[1][2] = false;
	table[2][2] = true;
	table[3][2] = false;
	table[4][2] = true;
	table[5][2] = false;
	table[6][2] = true;
	table[7][2] = false;
	table[8][2] = true;

	table[1][3] = false;
	table[2][3] = true;
	table[3][3] = false;
	table[4][3] = true;
	table[5][3] = false;
	table[6][3] = true;
	table[7][3] = true;
	table[8][3] = true;

	Logic L(inputs, outputs, Bill_Gates, table);

	L.addInput(&nodeA);
	L.addInput(&nodeB);
	L.addInput(&nodeC);
	L.addOutput(&output);
	L.addGate(&gate_and);
	L.addGate(&gate_or);

	bool y;
	y = L.checkTruthTable();
	return y;
}

int main() {
	bool s;
	std::string p = "and";
	std::string q = "or";
	s = result_Logic(p, q);

	std::cout << "something" << std::endl;

	std::cout << "the result is: " << s << std::endl;
	return 0;
}