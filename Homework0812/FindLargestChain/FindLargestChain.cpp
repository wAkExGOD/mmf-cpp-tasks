// FindLargestChain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 20;
    int arr[SIZE]{ 3, 3, 2, 4, 4, 4, 2, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7 };
    int maxCount = 0, count = 1, index = 0;

    for (int i = 1; i < SIZE; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        }
        else {
            if (count > maxCount) {
                maxCount = count;
                index = i - count;
            }
            count = 1;
        }
    }

    if (count > maxCount) {
        maxCount = count;
        index = SIZE - count;
    }

    cout << "The longest chain of identical elements is " << maxCount << " starting at index " << index << endl;

    return 0;
}
