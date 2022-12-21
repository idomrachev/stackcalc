#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cctype>
#include <cassert>
#include "Stack.h"

using namespace std;

//Stack<double> stack;

class StackCalc { // дописать класс
public:
    void PrintHelp() const;
    void start();
private:
    Stack<double> stack;
    void show();
    void onAdd(); //сложение
    void onSub(); //вычитание
    void onMul(); //умножение
    void onDiv(); //деление
    void onDup();
    void display();
};

void StackCalc::PrintHelp() const{
    cout <<
        "Commands of Stack Calculator:\n"
        "    +, -, *, /    arifmetic operations, \n"
        "    dup           duplicate the stack top,\n"
        "    q, quit       terminate the program.\n"
        "    clear          clear stack/\n"
        "    show       print stack."
        << endl;
}

void StackCalc::show() {
    Stack<double> stack1 = stack;
    for (int i=0; i<= stack.size(); i++)
    {
        cout << stack1.top() << " " << endl;
        stack1.pop();
    }

}

void StackCalc::start() {
    while (true) {
        string command;
        cin >> command;
        if (!cin.good())
            break;
        try {
            if (command == "+") {
                onAdd();
            } else if (command == "-") {
                onSub();
            } else if (command == "*") {
                onMul();
            } else if (command == "/") {
                onDiv();
            } else if (command == "show") {
                show();
            } else if (command == "=") {
                display();
            } else if (command == "dup") {
                onDup();
            } else if (command == "clear") {
                stack.clear();
                cout << "Stack is empty!"<<"\n";
            } else if (command == "q" || command == "quit") {
                break;
            } else if (
                (command.size() > 0 && isdigit(command[0]))
                ||
                (
                    command.size() >= 2 &&
                    (command[0] == '+' || command[0] == '-') &&
                    isdigit(command[1])
                )
            ) {
                double x = stod(command);
                stack.push(x);
            } else {
                cout << "Illegal command: " << command << endl;
                //PrintHelp();
            }
        } catch (const underflow_error& e) {
            cout << e.what() << endl;
        }
    }

}

int main() {

    StackCalc calc;
    calc.PrintHelp();
    calc.start();
    return 0;
}

void StackCalc::onAdd() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    double res = x + y;
    stack.push(res);
    display();
}

void StackCalc::onSub() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    double res = x - y;
    stack.push(res);
    display();
}

void StackCalc::onMul() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    double res = x * y;
    stack.push(res);
    display();
}

void StackCalc::onDiv() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    double res = x / y;
    stack.push(res);
    display();
}

void StackCalc::onDup() {
    double x = stack.top();
    stack.push(x);
}

void StackCalc::display() {
    cout << "= " << setprecision(15) << stack.top() << endl;
}


