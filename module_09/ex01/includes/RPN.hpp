#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN();
    RPN(const std::string& expr);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    bool validateInput(std::string& cleanExpr) const;

    long long calculate(const std::string& cleanExpr);

private:
    std::string expression_;

    bool isOperator(char c) const;

    static long long safeAdd(long long a, long long b);
    static long long safeSub(long long a, long long b);
    static long long safeMul(long long a, long long b);
    static long long safeDiv(long long a, long long b);
};

#endif
