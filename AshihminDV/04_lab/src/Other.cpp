#include "Other.h"
#include <limits> // for std::numeric_limits

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void mainMenu()
{
    char run = 'y';
    Polinomial p1;

    std::cout << "=== Polynomial Calculator ==="<< std::endl;
    std::cout << "Enter initial polynomial: ";
    std::cin >> p1;

    while (run != 'n')
    {
        std::cout << std::endl << "==============================" << std::endl;
        std::cout << "         Main Menu" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "1. Operations on polynomials" << std::endl;
        std::cout << "2. Operations on polynomial and constant" << std::endl;
        std::cout << "3. Calculate polynomial value" << std::endl;
        std::cout << "4. Change polynomial" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Current polynomial: " << p1 << std::endl;
        std::cout << "Select an option: ";

        int choice1;
        std::cin >> choice1;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            clearInput();
            continue;
        }

        switch (choice1) {
        case 1: {
            int op = 0;
            while (op != 4) {
                std::cout << "\n--- Polynomial Operations ---"<< std::endl;
                std::cout << "1. Add polynomial"<< std::endl;
                std::cout << "2. Subtract polynomial"<< std::endl;
                std::cout << "3. Multiply polynomial"<< std::endl;
                std::cout << "4. Back to main menu"<< std::endl;
                std::cout << "Choose an operation: ";
                std::cin >> op;

                if (std::cin.fail()) {
                    std::cout << "Invalid input."<< std::endl;
                    clearInput();
                    continue;
                }

                if (op >= 1 && op <= 3) {
                    std::cout << "Enter second polynomial: ";
                    Polinomial p2;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> p2;
                    std::cout << "Result: ";
                    if (op == 1) std::cout << p1 + p2 << ""<< std::endl;
                    else if (op == 2) std::cout << p1 - p2 << ""<< std::endl;
                    else if (op == 3) std::cout << p1 * p2 << ""<< std::endl;
                }
            }
            break;
        }

        case 2: {
            int op = 0;
            while (op != 4) {
                std::cout << "\n--- Polynomial & Constant ---"<< std::endl;
                std::cout << "1. Add constant"<< std::endl;
                std::cout << "2. Subtract constant"<< std::endl;
                std::cout << "3. Multiply by constant"<< std::endl;
                std::cout << "4. Back to main menu"<< std::endl;
                std::cout << "Choose an operation: ";
                std::cin >> op;

                if (std::cin.fail()) {
                    std::cout << "Invalid input."<< std::endl;
                    clearInput();
                    continue;
                }

                if (op >= 1 && op <= 3) {
                    double constant;
                    std::cout << "Enter constant: ";
                    std::cin >> constant;
                    if (std::cin.fail()) {
                        std::cout << "Invalid constant."<< std::endl;
                        clearInput();
                        continue;
                    }

                    std::cout << "Result: ";
                    if (op == 1) std::cout << p1 + constant << ""<< std::endl;
                    else if (op == 2) std::cout << p1 - constant << ""<< std::endl;
                    else if (op == 3) std::cout << p1 * constant << ""<< std::endl;
                }
            }
            break;
        }

        case 3: {
            double x, y, z;
            std::cout << "\n--- Evaluate Polynomial ---"<< std::endl;
            std::cout << "Enter values for x, y, z: ";
            std::cin >> x >> y >> z;

            if (std::cin.fail()) {
                std::cout << "Invalid input."<< std::endl;
                clearInput();
                continue;
            }

            std::cout << "Result: " << p1(x, y, z) << ""<< std::endl;
            break;
        }

        case 4: {
            std::cout << "Enter new polynomial: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> p1;
            break;
        }

        case 5: {
            std::cout << "Exiting... Goodbye!"<< std::endl;
            run = 'n';
            break;
        }

        default:
            std::cout << "Invalid choice. Please try again."<< std::endl;
            break;
        }
    }
}