/**
 * @file FourBitAdder.h
 * @brief Definition of the FOURBITADDER class for a 4-bit adder circuit.
 */

#ifndef FOURBITADDER_H
#define FOURBITADDER_H


#include <array>
#include "intern/LogicGates.h"
#include "intern/FullAdder.h"

 /**
  * @class FOURBITADDER
  * @brief Represents a 4-bit adder circuit.
  */
class FOURBITADDER
{
public:
    /**
     * @brief Constructor for the FOURBITADDER class.
     * @param id The identifier of the FOURBITADDER instance.
     */
    FOURBITADDER(const unsigned short int id);

    /**
     * @brief Destructor for the FOURBITADDER class.
     */
    ~FOURBITADDER();

    /**
     * @brief Sets the input values for the adder circuit.
     * @param val1 The 4-bit input value A.
     * @param val2 The 4-bit input value B.
     * @param k The carry-in value.
     */
    void setInput(std::array<unsigned short int, 4> val1, std::array<unsigned short int, 4> val2, const unsigned short int k);

    /**
     * @brief Updates the adder circuit to calculate the sum and carry-out.
     */
    void update();

    /**
     * @brief Get the sum output of the adder circuit.
     * @return The 4-bit sum.
     */
    std::array<unsigned short int, 4> sum() const;

    /**
     * @brief Get the carry-out of the adder circuit.
     * @return The carry-out value.
     */
    unsigned short int carryOut() const;

    /**
     * @brief Get the input value A (4-bit).
     * @return The 4-bit input value A.
     */
    std::array<unsigned short int, 4> in1() const;

    /**
     * @brief Get the input value B (4-bit).
     * @return The 4-bit input value B.
     */
    std::array<unsigned short int, 4> in2() const;

    /**
     * @brief Get the carry-in value (k).
     * @return The carry-in value (k).
     */
    unsigned short int carryIn() const;

    /**
     * @brief Get the carry-in and carry-out value (k) as an integer.
     * @return The carry-in and carry-out value (k).
     */
    unsigned short int k() const;

    /**
     * @brief Get a string representation of the FOURBITADDER instance.
     * @return A string representing the FOURBITADDER instance.
     */
    std::string repr();

private:
    AND* andGate; /**< Pointer to an AND gate instance. */
    NAND* nandGate; /**< Pointer to a NAND gate instance. */
    OR* orGate; /**< Pointer to an OR gate instance. */
    FULLADDER* fullAdder; /**< Pointer to a FULLADDER instance. */

    std::array<unsigned short int, 4> m_usiIn1; /**< The 4-bit input value A. */
    std::array<unsigned short int, 4> m_usiIn2; /**< The 4-bit input value B. */
    std::array<unsigned short int, 4> m_sum; /**< The 4-bit sum output. */
    unsigned short int m_carryIn; /**< The carry-in value (k). */
    unsigned short int m_carryOut; /**< The carry-out value. */
    unsigned short int m_k; /**< The carry-in and carry-out value (k). */
    std::string m_strID;
};

#endif // FOURBITADDER_H