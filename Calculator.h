#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>

class Calculator {
public:
    double basic(const std::string& line);  
    void rpn(const std::string& line);      
    void printStack() const;

private:
    std::vector<double> stack_;

    double pop();
};

#endif
