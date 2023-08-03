/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.


#include "../FourBitAdder.h"

FOURBITADDER::FOURBITADDER(const unsigned short int id)
{
	m_strID = std::to_string(id) + "FOURBITADDER";

	andGate = new AND(id);
	nandGate = new NAND(id);
	orGate = new OR(id);
	fullAdder = new FULLADDER(id);

	m_usiIn1 = { 0,0,0,0 };
	m_usiIn2 = { 0,0,0,0 };
	m_sum = { 0,0,0,0 };
	m_carryIn = 0;
	m_carryOut = 0;
	m_k = 0;
}

void FOURBITADDER::setInput(std::array<unsigned short int, 4> val1, std::array<unsigned short int, 4> val2, const unsigned short int k)
{
	for (int i = 0; i < 4; i++)
	{
		m_usiIn1[i] = val1[i];
		m_usiIn2[i] = val2[i];
	}
	m_carryIn = k;
	m_k = k;
}

void FOURBITADDER::update()
{
	unsigned short int out1;
	unsigned short int out2;

	for (int i = 0; i < 4; i++)
	{
		andGate->set_in1(m_usiIn2[i]);
		andGate->set_in2(!m_k);

		out1 = andGate->out();

		andGate->set_in1(!m_usiIn2[i]);
		andGate->set_in2(m_k);

		out2 = andGate->out();

		orGate->set_in1(out1);
		orGate->set_in2(out2);

		out2 = orGate->out();

		fullAdder->setInput(m_usiIn1[i], out2, m_carryIn);
		fullAdder->update();

		m_sum[i] = fullAdder->sum();
		m_carryIn = fullAdder->carryOut();
	}

	m_carryOut = m_carryIn;
}

std::array<unsigned short int, 4> FOURBITADDER::sum() const
{
	return m_sum;
}

unsigned short int FOURBITADDER::carryOut() const
{
	return m_carryOut;
}

std::array<unsigned short int, 4> FOURBITADDER::in1() const
{
	return m_usiIn1;
}

std::array<unsigned short int, 4> FOURBITADDER::in2() const
{
	return m_usiIn2;
}

unsigned short int FOURBITADDER::carryIn() const
{
	return m_carryIn;
}

unsigned short int FOURBITADDER::k() const
{
	return m_k;
}

std::string FOURBITADDER::repr()
{
	std::string A;
	std::string B;
	std::string S;

	for (int i = 0; i < 4; ++i) {
		A += std::to_string(m_usiIn1[i]);
		B += std::to_string(m_usiIn2[i]);
		S += std::to_string(m_sum[i]);
	}

	return "in1: " + A + "\n\tin2: " + B
		+ "\n\t\tK: " + std::to_string(m_k) + "\n\t\t\tsum: " + S + "\n\t\t\t\tcarryOut: " + std::to_string(m_carryOut);
}

FOURBITADDER::~FOURBITADDER()
{
	delete andGate;
	delete nandGate;
	delete orGate;
	delete fullAdder;
}