#include <iostream>
#include <string>

#include "Calculator.h"

using namespace std;

int main() {
    Calculator calc;
    bool rpnMode = true;
    string line;

    cout << "RPN Calculator (beta).\n";
    cout << "Type 'quit' to exit, 'rpn' to switch to RPN mode, 'basic' to switch to basic mode.\n";
    cout << "--- RPN (Reverse Polish Notation) Mode:   3 4 + 2 *   (type 'clear' to empty the stack)\n";
    cout << "--- Basic Mode: 3 + 4\n";

    while (true) {
        cout << (rpnMode ? "rpn> " : "basic> ");
        if (!getline(cin, line) || line == "quit") break;
        if (line.empty()) continue;

        if (line == "rpn") { rpnMode = true; continue; }
        if (line == "basic") { rpnMode = false; continue; }

        try {
            if (rpnMode) {
                calc.rpn(line);
                calc.printStack();
            } else {
                double result = calc.basic(line);
                cout << "= " << result << "\n";
            }
        } catch (const exception& e) {
            cout << "error: " << e.what() << "\n";
        }
    }
    return 0;
}
