#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> Explode(char seperator, const char* str)
{
    std::vector<std::string> result;
    // TODO: write code that "splits" the input string by the sperator
    // store each word in the resuts.
    int c = 0;
    std::string subString;
    while (str[c] != '\0')
    {
        if (!(str[c] - seperator))
        {
            if (subString != "")
                result.push_back(subString);
            subString.clear();
        }
        else
            subString.push_back(str[c]);
        c++;
    }
    if (subString != "")
        result.push_back(subString);

    return result;
}

int main(int argc, char* argv)
{
    std::cout << "---------------------------------------------------------" << std::endl;
    auto words = Explode(' ', "the quick brown fox jumps over the lazy dog");
    std::cout << "There are: " << words.size() << std::endl << std::endl;
    for (auto& w : words) {
        std::cout << w << std::endl;
    }
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << "---------------------------------------------------------" << std::endl;
    auto kvp = Explode('&', "aaa:10&bbb:20ccc:30&&&&&ddd:30");
    std::cout << "There are: " << kvp.size() << std::endl << std::endl;
    for (auto& w : kvp) {
        std::cout << w << std::endl;
    }
    std::cout << "---------------------------------------------------------" << std::endl;

    while (true);
    return 0;
}