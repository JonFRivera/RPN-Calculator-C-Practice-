#include "Calculator.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

static double compute(double a, char op, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("division by zero");
            return a / b;
        default:
            throw runtime_error(string("unknown operator '") + op + "'");
    }
}

double Calculator::basic(const string& line) {
    istringstream in(line);
    double a, b;
    char op;
    if (!(in >> a >> op >> b)) throw runtime_error("use: number operator number");
    return compute(a, op, b);
}

double Calculator::pop() {
    if (stack_.empty()) throw runtime_error("not enough numbers on the stack");
    double v = stack_.back();
    stack_.pop_back();
    return v;
}

void Calculator::rpn(const string& line) {
    vector<double> backup = stack_; 
    try {
        istringstream in(line);
        string tok;
        while (in >> tok) {
            char* end = nullptr;
            double num = strtod(tok.c_str(), &end);
            if (end != tok.c_str() && *end == '\0') {
                stack_.push_back(num);
            } else if (tok == "clear") {
                stack_.clear();
            } else if (tok.size() == 1) {
                double b = pop();
                double a = pop();
                stack_.push_back(compute(a, tok[0], b));
            } else {
                throw runtime_error("unknown token '" + tok + "'");
            }
        }
    } catch (...) {
        stack_ = backup;
        throw;
    }
}

void Calculator::printStack() const {
    cout << "[";
    for (double v : stack_) cout << ' ' << v;
    cout << " ]\n";
}
