#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/HalfAdder.h"

TEST(HALFADDERConstructorTest, test001) {

	// create an object
	HALFADDER halfadder1(1);

	// check that the object is constructed correctly
	unsigned short int in1 = halfadder1.in1();
	ASSERT_EQ(in1, 0);
	unsigned short int in2 = halfadder1.in2();
	ASSERT_EQ(in2, 0);
	unsigned short int sum = halfadder1.sum();
	ASSERT_EQ(0, sum);
	unsigned short int cout = halfadder1.carry();
	ASSERT_EQ(0, cout);
}


TEST(HALFADDERTruthTableTest, test002) {
    // Create an object of the HalfAdder class
    HALFADDER halfAdder1(1);

    // Define the truth table inputs and expected outputs
    const unsigned short int truthTableInputs[4][2] = {
        {0, 0}, // Row 1: A=0, B=0
        {0, 1}, // Row 2: A=0, B=1
        {1, 0}, // Row 3: A=1, B=0
        {1, 1}  // Row 4: A=1, B=1
    };

    const unsigned short int truthTableOutputs[4][2] = {
        {0, 0}, // Row 1: Sum=0, Carry=0
        {1, 0}, // Row 2: Sum=1, Carry=0
        {1, 0}, // Row 3: Sum=1, Carry=0
        {0, 1}  // Row 4: Sum=0, Carry=1
    };

    // Test each row of the truth table
    for (int i = 0; i < 4; ++i) {
        unsigned short int A = truthTableInputs[i][0];
        unsigned short int B = truthTableInputs[i][1];

        unsigned short int expectedSum = truthTableOutputs[i][0];
        unsigned short int expectedCarry = truthTableOutputs[i][1];

        // Set the inputs for the half adder
        halfAdder1.setInput(A, B);

        // Calculate the actual outputs
        halfAdder1.update();

        // Get the actual outputs
        unsigned short int actualSum = halfAdder1.sum();
        unsigned short int actualCarry = halfAdder1.carry();

        // Compare the actual outputs with the expected outputs
        ASSERT_EQ(expectedSum, actualSum);
        ASSERT_EQ(expectedCarry, actualCarry);
    }
}
