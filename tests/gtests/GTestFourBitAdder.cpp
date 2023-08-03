#include <gtest/gtest.h>
#include "../../source/FourBitAdder/FourBitAdder.h"

TEST(FOURBITADDERConstructorTest, test001) {

	// create an object
	FOURBITADDER fourbitadder1(1);

	fourbitadder1.in1();
	// check that the object is constructed correctly
	std::array<unsigned short int, 4> in1 = fourbitadder1.in1();
	for (int i = 0; i < 4; ++i) {
		ASSERT_EQ(in1[i], 0);
	}
	std::array<unsigned short int, 4> in2 = fourbitadder1.in2();
	for (int i = 0; i < 4; ++i) {
		ASSERT_EQ(in2[i], 0);
	}
	unsigned short int k = fourbitadder1.k();
	ASSERT_EQ(k, 0);
	std::array<unsigned short int, 4> sum = fourbitadder1.sum();
	for (int i = 0; i < 4; ++i) {
		ASSERT_EQ(0, sum[i]);
	}
	unsigned short int cout = fourbitadder1.carryOut();
	ASSERT_EQ(0, cout);
}