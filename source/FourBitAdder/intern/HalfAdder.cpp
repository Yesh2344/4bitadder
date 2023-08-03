
#include "HalfAdder.h"

HALFADDER::HALFADDER(const unsigned short int id)
{
	m_strID = std::to_string(id) + "HALFADDER";

	andGate = new AND(id);
	nandGate = new NAND(id);
	orGate = new OR(id);

	m_usiIn1 = 0;
	m_usiIn2 = 0;
	m_sum = 0;
	m_carry = 0;
}

void HALFADDER::setInput(const unsigned short int val1, const unsigned short int val2)
{
	m_usiIn1 = val1;
	m_usiIn2 = val2;
}

void HALFADDER::update()
{
	andGate->set_in1(m_usiIn1);
	andGate->set_in2(m_usiIn2);

	m_carry = andGate->out();

	andGate->set_in1(m_usiIn1);
	andGate->set_in2(!m_usiIn2);

	const unsigned short int out1 = andGate->out();

	andGate->set_in1(!m_usiIn1);
	andGate->set_in2(m_usiIn2);

	const unsigned short int out2 = andGate->out();

	orGate->set_in1(out1);
	orGate->set_in2(out2);

	m_sum = orGate->out();
}

unsigned short int HALFADDER::sum() const
{
	return m_sum;
}

unsigned short int HALFADDER::carry() const
{
	return m_carry;
}

unsigned short int HALFADDER::in1() const
{
	return m_usiIn1;
}

unsigned short int HALFADDER::in2() const
{
	return m_usiIn2;
}

std::string HALFADDER::repr()
{
	return "in1: " + std::to_string(m_usiIn1) + "\n\tin2: " + std::to_string(m_usiIn2)
		+ "\n\t\tsum: " + std::to_string(m_sum) + "\n\t\t\tcarry: " + std::to_string(m_carry);
}

HALFADDER::~HALFADDER()
{
	delete andGate;
	delete orGate;
	delete nandGate;
}