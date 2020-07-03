#include <iostream>
#include <vector>
#include <cmath>
int MaxDifference(const std::vector<int>& numbers)
{
    // find the smallest and largest number, and return the difference between them.
    // How many different ways can you achieve this?
    // - using loops? for loop?, range based for?, using iterator instead of random access? other?
    // - using recursion?
    // - making use of existing methods in the standard template library?
    // - what is the preformance of of your solution?
    // - - can you write it another way for faster execution time?

    int minNumber = INT_MAX;
    int maxNumber = INT_MIN;
    for (auto i : numbers)
    {
        minNumber = i < minNumber ? i : minNumber;
        maxNumber = i > maxNumber ? i : maxNumber;
    }

    return maxNumber - minNumber;

    //Performance = O(n)
}
int MaxDifference2(const std::vector<int>& numbers)
{
    // OPTIONAL CHALLENGE:
    // find the smallest and largest number, and return the difference between them.
    // Constraint: the selected largest number must appear AFTER the selected smalest number.
    // Constraint: the selected smallest number must appear BEFORE the selected largest number.
    // Note: with these constraints, there may be sqeuences that where a min and max cannot be calculated
    // How many different ways can you achieve this?
    // - using loops? for loop?, range based for?, using iterator instead of random access? other?
    // - using recursion?
    // - making use of existing methods in the standard template library?
    // - what is the preformance of of your solution?

    int minNumber = INT_MAX;
    int maxNumber = INT_MIN;
    int minIndex = 0;
    int maxIndex = 0;
    int differenceA = 0;
    int differenceB = 0;

    int size = numbers.size();
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] > maxNumber)
        {
            maxNumber = numbers[i];
            maxIndex = i;
        }
    }
    for (int j = 0; j < maxIndex; j++)
    {
        if (numbers[j] < minNumber)
            minNumber = numbers[j];
    }

    differenceA = maxNumber - minNumber;

    minNumber = INT_MAX;
    maxNumber = INT_MIN;
    minIndex = 0;
    maxIndex = 0;
    for (int j = 0; j < size; j++)
    {
        if (numbers[j] < minNumber)
        {
            minNumber = numbers[j];
            minIndex = j;
        }
    }
    if (minIndex + 1 != size)
    {
        for (int i = minIndex + 1; i < size; i++)
        {
            if (numbers[i] > maxNumber)
                maxNumber = numbers[i];
        }
        differenceB = maxNumber - minNumber;
    }

    return differenceA > differenceB ? differenceA : differenceB;
}
int main(int argc, char** argv)
{
    std::cout << MaxDifference({ 10, 15, 12, 8, 7, 31, 8 }) << std::endl; // 31 - 7 = 24
    std::cout << MaxDifference({ 12, 0, 4, 9, 2, 5, 8, 3 }) << std::endl; // 12 - 0 = 12
    std::cout << MaxDifference2({ 10, 15, 12, 8, 7, 31, 2 }) << std::endl; // 31 - 7 = 24 
    std::cout << MaxDifference2({ 12, 0, 4, 9, 2, 5, 8, 3 }) << std::endl; // 9 - 0 = 9 
    std::cout << MaxDifference2({ 12, 13, 14, 5, 6, 7, 8 }) << std::endl; // 8 - 5 = 3
    std::cout << MaxDifference2({ 12, 13, 14, 8, 7, 6, 5 }) << std::endl; // ?? cannot select min or max?
    std::cout << MaxDifference2({ 1, 2, 3, 4, 5, 6, 7, 8 }) << std::endl; // ?? cannot select a min or max?

    while (true);
    return 0;
}