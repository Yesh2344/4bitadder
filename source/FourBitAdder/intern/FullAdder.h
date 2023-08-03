/**
 * @class FULLADDER
 * @brief Represents a full adder circuit.
 */

#ifndef FULLADDER_H
#define FULLADDER_H

#include "LogicGates.h"

class FULLADDER
{
public:
    /**
     * @brief Constructor for the FULLADDER class.
     * @param id The identifier of the FULLADDER instance.
     */
    FULLADDER(const unsigned short int id);

    /**
     * @brief Sets the input values for the full adder circuit.
     * @param in1 The first input bit.
     * @param in2 The second input bit.
     * @param carryIn The carry-in bit.
     */
    void setInput(const unsigned short int in1, const unsigned short int in2, const unsigned short int carryIn);

    /**
     * @brief Updates the full adder circuit to calculate the sum and carry-out.
     */
    void update();

    /**
     * @brief Get the sum output of the full adder circuit.
     * @return The sum output bit.
     */
    const unsigned short int sum() const;

    /**
     * @brief Get the carry-out of the full adder circuit.
     * @return The carry-out bit.
     */
    const unsigned short int carryOut() const;

    /**
     * @brief Get the first input bit of the full adder circuit.
     * @return The first input bit.
     */
    const unsigned short int in1() const;

    /**
     * @brief Get the second input bit of the full adder circuit.
     * @return The second input bit.
     */
    const unsigned short int in2() const;

    /**
     * @brief Get the carry-in bit of the full adder circuit.
     * @return The carry-in bit.
     */
    const unsigned short int carryIn() const;

    /**
     * @brief Get a string representation of the FULLADDER instance.
     * @return A string representing the FULLADDER instance.
     */
    std::string repr();

    /**
     * @brief Destructor for the FULLADDER class.
     */
    ~FULLADDER();

private:
    AbstractGate* andGate; /**< Pointer to an AND gate instance. */
    AbstractGate* nandGate; /**< Pointer to a NAND gate instance. */
    AbstractGate* orGate; /**< Pointer to an OR gate instance. */

    unsigned short int m_usiIn1; /**< The first input bit. */
    unsigned short int m_usiIn2; /**< The second input bit. */
    unsigned short int m_carryIn; /**< The carry-in bit. */
    unsigned short int m_sum; /**< The sum output bit. */
    unsigned short int m_carryOut; /**< The carry-out bit. */

    std::string m_strID; /**< Identifier of the FULLADDER instance. */
};

#endif // FULLADDER_H