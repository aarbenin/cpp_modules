#include "RPN.hpp"
#include <algorithm>
#include <cctype>
#include <climits>
#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN() : expression_("") {}

RPN::RPN(const std::string& expr) : expression_(expr) {}

RPN::RPN(const RPN& other) : expression_(other.expression_) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        expression_ = other.expression_;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::validateInput(std::string& cleanExpr) const {
    cleanExpr = expression_;
    cleanExpr.erase(
        std::remove_if(cleanExpr.begin(), cleanExpr.end(),
                       [](unsigned char c) { return std::isspace(c); }),
        cleanExpr.end());
    if (cleanExpr.empty())
        return false;

    for (char c : cleanExpr) {
        if (!std::isdigit(c) && !isOperator(c))
            return false;
    }

    if (!std::isdigit(cleanExpr[0]))
        return false;

    int counter = 0;

    for (char c : cleanExpr) {
        if (std::isdigit(c))
            ++counter;
        else if (isOperator(c))
            --counter;

        if (counter < 1)
            return false;
    }
    return (counter == 1);
}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

long long RPN::safeAdd(long long a, long long b) {
    __int128 temp = (__int128)a + (__int128)b;
    if (temp > LLONG_MAX || temp < LLONG_MIN)
        throw std::runtime_error("Overflow in addition");
    return (long long)temp;
}

long long RPN::safeSub(long long a, long long b) {
    __int128 temp = (__int128)a - (__int128)b;
    if (temp > LLONG_MAX || temp < LLONG_MIN)
        throw std::runtime_error("Overflow in subtraction");
    return (long long)temp;
}

long long RPN::safeMul(long long a, long long b) {
    __int128 temp = (__int128)a * (__int128)b;
    if (temp > LLONG_MAX || temp < LLONG_MIN)
        throw std::runtime_error("Overflow in multiplication");
    return (long long)temp;
}

long long RPN::safeDiv(long long a, long long b) {
    if (b == 0)
        throw std::runtime_error("Division by zero");
    __int128 temp = (__int128)a / (__int128)b;
    if (temp > LLONG_MAX || temp < LLONG_MIN)
        throw std::runtime_error("Overflow in division");
    return (long long)temp;
}

long long RPN::calculate(const std::string& cleanExpr) {
    std::stack<long long> st;
    for (char c : cleanExpr) {
        if (std::isdigit(c)) {
            st.push(c - '0');
        } else if (isOperator(c)) {
            if (st.size() < 2)
                throw std::runtime_error("Not enough operands");
            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            long long result = 0;
            switch (c) {
            case '+':
                result = safeAdd(a, b);
                break;
            case '-':
                result = safeSub(a, b);
                break;
            case '*':
                result = safeMul(a, b);
                break;
            case '/':
                result = safeDiv(a, b);
                break;
            default:
                throw std::runtime_error("Unexpected operator");
            }
            st.push(result);
        }
    }
    if (st.size() != 1)
        throw std::runtime_error("Invalid RPN expression (extra operands?)");
    return st.top();
}
