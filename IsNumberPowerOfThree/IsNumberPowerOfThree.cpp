#include <iostream>

int main()
{
    int r = 1, i = 1, c;

    std::cin >> c;

    while (i < 5) {

        r = r + 3;

        i = i + c;

    }

    std::cout << r;

    return 0;
}