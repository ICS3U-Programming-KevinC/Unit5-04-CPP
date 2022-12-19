// Copyright (c) 2022 Kevin Csiffary All rights reserved.
//
// Created by: Kevin Csiffary
// Date: Dec. 11, 2022
// This program is a calculator

#include <cmath>
#include <iostream>

// calculates the result with the given sign and numbers
float Calculate(std::string sign, float firstNumber, float secondNumber) {
    if (sign == "+") {
        return firstNumber + secondNumber;
    } else if (sign == "-") {
        return firstNumber - secondNumber;
    } else if (sign == "*") {
        return firstNumber * secondNumber;
    } else if (sign == "/") {
        return firstNumber / secondNumber;
    } else if (sign == "%") {
        return static_cast<int>(firstNumber) % static_cast<int>(secondNumber);
    } else {
        // returns null in there is no sign
        return NULL;
    }
}

int main() {
    // initialize variable for the sign
    std::string sign;

    // initialize string variables for the numbers
    std::string userFirstNumStr;
    std::string userSecondNumStr;

    // initialize string variables for the numbers
    float userFirstNum;
    float userSecondNum;

    // initialize the variable for the result
    float result;

    // get user input for the sign
    std::cout << "Enter the operation you want to preform (+, -, *, /, %): ";
    std::cin >> sign;

    // get user input for the two numbers
    std::cout << "Enter the first number: ";
    std::cin >> userFirstNumStr;
    std::cout << "Enter the second number: ";
    std::cin >> userSecondNumStr;

    try {
        // cast the two numbers
        userFirstNum = std::stof(userFirstNumStr);
        userSecondNum = std::stof(userSecondNumStr);

        // check if the user is trying to divide by zero
        if ((userSecondNum == 0) & (sign == "/")) {
            std::cout << "You cant divide by zero.\n";
        } else {
            // calls the function with the sign and numbers
            result = Calculate(sign, userFirstNum, userSecondNum);

            // checks if the sign from the user was invalid
            if (result == NULL) {
                std::cout << sign << " is not a valid sign\n";
            } else {
                // displays the result
                std::cout << "The result of " << userFirstNum << " "
                << sign << " " << userSecondNum << " is " << result << "\n";
            }
        }
        // catch input errors
    } catch (std::invalid_argument) {
        std::cout << "Please input a valid number\n";
    }
}
