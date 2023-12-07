#include <iostream>
using namespace std;

int main()
{
    int numbers[4]{ 1, 2, 3, 4 };
    int k = 3;
    int arrayLength = sizeof(numbers) / sizeof(int);

    for (int i = 0; i < arrayLength; i++) {
        if (i >= k) {
            numbers[i] = numbers[i + 1];
        }
        if (i == (arrayLength - 1)) {
            numbers[i] = 0;
        }
    }

    // output:
    for (int i = 0; i < 4; i++) {
        cout << numbers[i] <<endl;
    }

    return 0;
}