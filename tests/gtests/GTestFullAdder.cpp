#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/FullAdder.h"

TEST(FULLADDERConstructorTest, test001) {

	// create an object
	FULLADDER fulladder1(1);

	// check that the object is constructed correctly
	unsigned short int in1 = fulladder1.in1();
	ASSERT_EQ(in1, 0);
	unsigned short int in2 = fulladder1.in2();
	ASSERT_EQ(in2, 0);
	unsigned short int cin = fulladder1.carryIn();
	ASSERT_EQ(cin, 0);
	unsigned short int sum = fulladder1.sum();
	ASSERT_EQ(0, sum);
	unsigned short int cout = fulladder1.carryOut();
	ASSERT_EQ(0, cout);
}

TEST(FULLADDERTruthTableTest, test002)
{
	FULLADDER fulladder1(1);

    // Define the truth table inputs and expected outputs
    const unsigned short int truthTableInputs[8][3] = {
        {0, 0, 0}, // Row 1: A=0, B=0, Cin=0
        {0, 0, 1}, // Row 2: A=0, B=0, Cin=1
        {0, 1, 0}, // Row 3: A=0, B=1, Cin=0
        {0, 1, 1}, // Row 4: A=0, B=1, Cin=1
        {1, 0, 0}, // Row 5: A=1, B=0, Cin=0
        {1, 0, 1}, // Row 6: A=1, B=0, Cin=1
        {1, 1, 0}, // Row 7: A=1, B=1, Cin=0
        {1, 1, 1}  // Row 8: A=1, B=1, Cin=1
    };

    const unsigned short int truthTableOutputs[8][2] = {
        {0, 0}, // Row 1: Sum=0, Cout=0
        {1, 0}, // Row 2: Sum=1, Cout=0
        {1, 0}, // Row 3: Sum=1, Cout=0
        {0, 1}, // Row 4: Sum=0, Cout=1
        {1, 0}, // Row 5: Sum=1, Cout=0
        {0, 1}, // Row 6: Sum=0, Cout=1
        {0, 1}, // Row 7: Sum=0, Cout=1
        {1, 1}  // Row 8: Sum=1, Cout=1
    };

    // Test each row of the truth table
    for (int i = 0; i < 8; ++i) {
        unsigned short int A = truthTableInputs[i][0];
        unsigned short int B = truthTableInputs[i][1];
        unsigned short int Cin = truthTableInputs[i][2];

        unsigned short int expectedSum = truthTableOutputs[i][0];
        unsigned short int expectedCout = truthTableOutputs[i][1];

        // Set the inputs for the full adder
        fulladder1.setInput(A, B, Cin);

        // Calculate the actual outputs
        fulladder1.update();

        // Get the actual outputs
        unsigned short int actualSum = fulladder1.sum();
        unsigned short int actualCout = fulladder1.carryOut();

        // Compare the actual outputs with the expected outputs
        ASSERT_EQ(expectedSum, actualSum);
        ASSERT_EQ(expectedCout, actualCout);
    }
}