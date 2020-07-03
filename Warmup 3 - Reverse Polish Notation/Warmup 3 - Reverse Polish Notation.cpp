#include <iostream>
#include <vector>
#include <string>
float RPN(const std::string equation)
{
    std::vector<int> stack;
    std::vector<char> word;
    int c = 0;
    bool firstValue = true;
    int value = 0;
    while (equation[c] != '\0')
    {
        if (equation[c] >= '0' && equation[c] <= '9')
        {
            word.push_back(equation[c]);
        }
        else if (equation[c] == ' ')
        {
            if (equation[c + 1] < '0' || equation[c = 1] > '9')
            {
                if (equation[c] == '+')
                {
                    stack.pop_back();
                    stack[stack.size() - 2] = stack[stack.size() - 2] + stack[stack.size() - 1];
                    stack.pop_back();
                }
                else if (equation[c] == '-')
                {
                    stack.pop_back();
                    stack[stack.size() - 2] = stack[stack.size() - 2] - stack[stack.size() - 1];
                    stack.pop_back();
                }
                else if (equation[c] == '*')
                {
                    stack.pop_back();
                    stack[stack.size() - 2] = stack[stack.size() - 2] * stack[stack.size() - 1];
                    stack.pop_back();
                }
                else if (equation[c] == '/')
                {
                    stack.pop_back();
                    stack[stack.size() - 2] = stack[stack.size() - 2] / stack[stack.size() - 1];
                    stack.pop_back();
                }
            }
            else
            {
                char digit = 1;
                for (char& letter : word)
                {
                    letter -= 48;
                    value *= digit;
                    value += letter;
                    digit *= 10;
                }
                stack.push_back(value);
                digit = 1;
                word.clear();
                value = 0;
            }
        }
        c++;
    }

    return stack[0];
}

int main(int argc, char** argv)
{
    {
        std::string equation = "10 20 +";
        std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 30" << std::endl;
    }
    {
        std::string equation = "10 20 30 + *";
        std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 500" << std::endl;
    }
    {
        std::string equation = "20 10 / 4 *";
        std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 8" << std::endl;
    }
    {
        std::string equation = "20 10 - 15 +";
        std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 35" << std::endl;
    }

    while (true);
    return 0;
}