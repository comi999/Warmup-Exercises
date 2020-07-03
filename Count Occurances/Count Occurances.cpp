#include <iostream>
#include <string>

int CountOccurances(const std::string& phrase, const std::string& searchTerm)
{
    // TODO: Write your code here
    if (searchTerm.size() == 0)
        return phrase.size() + 1;

    if (searchTerm.size() > phrase.size())
        return 0;

    //Search Term characteristics
    int endBuffer = phrase.size() - searchTerm.size() + 1;
    char first = searchTerm.front();
    char last = searchTerm.back();
    int size = searchTerm.size();
    
    bool match = true;
    int count = 0;

    for (int i = 0; i < endBuffer; i++)
    {
        match = true;
        if (phrase[i] == first && phrase[i + size - 1] == last)
        {
            for (int j = 1; j < size - 1; j++)
            {
                if (phrase[i + j] != searchTerm[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
                count++;
        }
    }

    return count;
}
int main(int argc, char** argv)
{
    std::string phrase1 = "the quick brown fox jumps over the lazy dog";
    std::string phrase2 = "hello world";
    std::string phrase3 = "aaaaaaaaaaa";
    std::cout << CountOccurances(phrase1, "the") << std::endl;  // -> 2
    std::cout << CountOccurances(phrase1, "o") << std::endl;    // -> 4
    std::cout << CountOccurances(phrase2, "l") << std::endl;    // -> 3
    std::cout << CountOccurances(phrase2, "ll") << std::endl;   // -> 1
    std::cout << CountOccurances(phrase3, "aaa") << std::endl;  // -> 9
    std::cout << CountOccurances(phrase3, "a") << std::endl;    // -> 11

    std::cout << CountOccurances(phrase3, "") << std::endl; // -> 
    std::cout << CountOccurances("", "a") << std::endl; // -> 1

    std::cout << CountOccurances("", "") << std::endl; // -> 1

    while (true);
    return 0;
}