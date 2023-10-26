#include <iostream>

int main()
{
    double num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    while (num > 1) {
        num /= 3;

        if (num == 1) {
            std::cout << "Yes";
            return 0;
        }
    }

    std::cout << "No";

    return 0;
}