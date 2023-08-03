/**
 * @class HALFADDER
 * @brief Represents a half adder circuit.
 */

#ifndef HALFADDER_H
#define HALFADDER_H

#include "LogicGates.h"

class HALFADDER
{
public:
    /**
     * @brief Constructor for the HALFADDER class.
     * @param id The identifier of the HALFADDER instance.
     */
    HALFADDER(const unsigned short int id);

    /**
     * @brief Sets the input values for the half adder circuit.
     * @param in1 The first input bit.
     * @param in2 The second input bit.
     */
    void setInput(const unsigned short int in1, const unsigned short int in2);

    /**
     * @brief Updates the half adder circuit to calculate the sum and carry.
     */
    void update();

    /**
     * @brief Get the sum output of the half adder circuit.
     * @return The sum output bit.
     */
    unsigned short int sum() const;

    /**
     * @brief Get the carry output of the half adder circuit.
     * @return The carry output bit.
     */
    unsigned short int carry() const;

    /**
     * @brief Get the first input bit of the half adder circuit.
     * @return The first input bit.
     */
    unsigned short int in1() const;

    /**
     * @brief Get the second input bit of the half adder circuit.
     * @return The second input bit.
     */
    unsigned short int in2() const;

    /**
     * @brief Get a string representation of the HALFADDER instance.
     * @return A string representing the HALFADDER instance.
     */
    std::string repr();

    /**
     * @brief Destructor for the HALFADDER class.
     */
    ~HALFADDER();

private:
    AbstractGate* andGate; /**< Pointer to an AND gate instance. */
    AbstractGate* nandGate; /**< Pointer to a NAND gate instance. */
    AbstractGate* orGate; /**< Pointer to an OR gate instance. */

    unsigned short int m_usiIn1; /**< The first input bit. */
    unsigned short int m_usiIn2; /**< The second input bit. */
    unsigned short int m_sum; /**< The sum output bit. */
    unsigned short int m_carry; /**< The carry output bit. */

    std::string m_strID; /**< Identifier of the HALFADDER instance. */
};

#endif // HALFADDER_H