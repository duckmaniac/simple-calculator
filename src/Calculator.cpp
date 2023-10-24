#include "Calculator.h"

bool Calculator::is_operator_found(const std::string& expression, char operator_symbol) {
    return expression.find(operator_symbol) != std::string::npos;
}

big_float Calculator::process_operator(const std::string& expression, char operator_symbol, 
    big_float(*operation)(big_float, big_float)) {
    auto operator_pos = expression.find(operator_symbol);
    big_float left_operand = recursive_calculate(expression.substr(0, operator_pos));
    big_float right_operand = recursive_calculate(expression.substr(operator_pos + 1));
    return operation(left_operand, right_operand);
}

// Replaces instances of binary minus operator in the expression with "+-" 
// to avoid ambiguity during processing. Returns the processed expression.
std::string Calculator::replace_binary_minus(const std::string& expression) {
    std::string processed_expresion = expression;
    size_t pos = 0;
    std::string minus = "-";
    std::string plus_minus = "+-";

    while ((pos = processed_expresion.find(minus, pos)) != std::string::npos) {
        // If minus is a binary operator then replace it
        if (pos > 0 && (isdigit(processed_expresion[pos - 1]) || processed_expresion[pos - 1] == '.')) {
            processed_expresion.replace(pos, minus.length(), plus_minus);
        }
        pos += plus_minus.length();
    }

    return processed_expresion;
}

big_float add_operation(big_float left, big_float right) {
    return left + right;
}

big_float multiply_operation(big_float left, big_float right) {
    return left * right;
}

big_float divide_operation(big_float left, big_float right) {
    return left / right;
}

big_float Calculator::recursive_calculate(const std::string& expression) {
    // Parsing plus operator
    if (is_operator_found(expression, '+')) {
        return process_operator(expression, '+', add_operation);
    }

    // Parsing multiply operator
    if (is_operator_found(expression, '*')) {
        return process_operator(expression, '*', multiply_operation);
    }

    // Parsing divide operator
    if (is_operator_found(expression, '/')) {
        return process_operator(expression, '/', divide_operation);
    }

    // Base recursion case
    return expression.empty() ? 0.0L : big_float(expression);
}

big_float Calculator::calculate(const std::string& expression) {
    return recursive_calculate(replace_binary_minus(expression));
}