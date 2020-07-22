#include <iostream>
#include <vector>
#include <map>

struct Vector2
{
    int x, y;
};

int findOdd(std::vector<int> numbers)
{
    std::map<int, int> tally;
    for (auto& i : numbers)
    {
        auto position = tally.find(i);

        if (position != tally.end())
            position->second++;
        else
            tally.insert({i, 1});
    }
    
    int oddInteger = 0;
    for (auto& j : tally)
    {
        float a = 0.5f * j.second;
        int b = j.second * 0.5f;
        if (a != b)
            return j.first;
    }
    return 0;
}

int main()
{
    std::vector<int> set1 = { 1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5 };
    std::vector<int> set2 = { 20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5 };
    std::vector<int> set3 = { 10 };
    int number1 = findOdd(set1); // number1 = -1
    int number2 = findOdd(set2); // number2 =  5
    int number3 = findOdd(set3); // number3 =  10

    std::cout << number1 << ", " << number2 << ", " << number3;

    while (true);

}
