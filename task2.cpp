#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "=================================\n";
    std::cout << "        SIMPLE CALCULATOR        \n";
    std::cout << "=================================\n";

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;
    
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "\nResult: ";
    switch (operation) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
            } else {
                std::cout << "Error! Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operator entered." << std::endl;
            break;
    }

    return 0;
}
