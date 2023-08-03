
#include "FullAdder.h"

FULLADDER::FULLADDER(const unsigned short int id)
{
	m_strID = std::to_string(id) + "FULLADDER";

	andGate = new AND(id);
	nandGate = new NAND(id);
	orGate = new OR(id);

	m_usiIn1 = 0;
	m_usiIn2 = 0;
	m_carryIn = 0;
	m_sum = 0;
	m_carryOut = 0;
}

void FULLADDER::setInput(const unsigned short int val1, const unsigned short int val2, const unsigned short int carryIn)
{
	m_usiIn1 = val1;
	m_usiIn2 = val2;
	m_carryIn = carryIn;
}

void FULLADDER::update()
{
	// carry out
	andGate->set_in1(m_usiIn1);
	andGate->set_in2(m_carryIn);

	unsigned short int out1 = andGate->out();

	andGate->set_in1(m_usiIn2);

	unsigned short int out2 = andGate->out();

	orGate->set_in1(out1);
	orGate->set_in2(out2);

	out2 = orGate->out();

	andGate->set_in1(m_usiIn1);
	andGate->set_in2(m_usiIn2);

	out1 = andGate->out();

	orGate->set_in1(out1);
	orGate->set_in2(out2);

	m_carryOut = orGate->out();

	// sum
	andGate->set_in1(m_usiIn1);
	andGate->set_in2(!m_usiIn2);


	out1 = andGate->out();

	andGate->set_in1(!m_usiIn1);
	andGate->set_in2(m_usiIn2);

	out2 = andGate->out();

	orGate->set_in1(out1);
	orGate->set_in2(out2);

	out2 = orGate->out();

	andGate->set_in1(out2);
	andGate->set_in2(!m_carryIn);

	out1 = andGate->out();

	andGate->set_in1(!out2);
	andGate->set_in2(m_carryIn);


	out2 = andGate->out();

	orGate->set_in1(out1);
	orGate->set_in2(out2);


	m_sum = orGate->out();
}

const unsigned short int FULLADDER::sum() const
{
	return m_sum;
}

const unsigned short int FULLADDER::carryOut() const
{
	return m_carryOut;
}

const unsigned short int FULLADDER::in1() const
{
	return m_usiIn1;
}

const unsigned short int FULLADDER::in2() const
{
	return m_usiIn2;
}

const unsigned short int FULLADDER::carryIn() const
{
	return m_carryIn;
}

std::string FULLADDER::repr()
{
	return "in1: " + std::to_string(m_usiIn1) + "\n\tin2: " + std::to_string(m_usiIn2)
		+ "\n\t\tcarryIn: " + std::to_string(m_carryIn) + "\n\t\t\tsum: " + std::to_string(m_sum) + "\n\t\t\t\tcarryOut: " + std::to_string(m_carryOut);
}

FULLADDER::~FULLADDER()
{
	delete andGate;
	delete orGate;
	delete nandGate;
}