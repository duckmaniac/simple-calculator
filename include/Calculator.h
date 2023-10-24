#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <boost/multiprecision/cpp_dec_float.hpp>

constexpr int PRECISION = 25;

using big_float = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<PRECISION>>;

// This class provides static method to calculate a math expression provided as a string. 
class Calculator {
private:
    // Checks if a given operator is found in the expression. 
    static bool is_operator_found(const std::string& expression, char operator_symbol);

    // Processes a given operator in the expression by applying the provided operation function. 
    static big_float process_operator(const std::string& expression, char operator_symbol, 
        big_float (*operation)(big_float, big_float));

    // Replaces instances of binary minus operators in the expression for easier processing.
    // Returns the modified version of expression. 
    static std::string replace_binary_minus(const std::string& expression);

    // Recursively calculates the value of the expression, handling operators priority. 
    static big_float recursive_calculate(const std::string& expression);

public:
    // Calculates the value of the expression. 
    // Does not handle expressions with parentheses or advanced math functions. 
    static big_float calculate(const std::string& expression);
};

#endif // CALCULATOR_H