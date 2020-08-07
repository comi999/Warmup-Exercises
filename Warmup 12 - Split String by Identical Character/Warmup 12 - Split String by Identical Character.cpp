#include <iostream>
#include <vector>

std::vector<std::string> splitGroups(std::string s) 
{
    std::vector<std::string> result;
    char count = 0, current;
    for (int i = 0; i < s.size(); i++)
    {
        current = s[i];
        while (current == *(&s[i] + count) && s[i] != '\0') count++;
        result.push_back(s.substr(i, count));
        i += -1 + count; count = 0;
    }
    return result;
}

int main()
{
    std::string a = "555";
    std::string b = "5556667788";
    std::string c = "aaabbbaabbab";
    std::string d = "abbbcc88999&&!!!_";

    std::cout << a << ":" << std::endl;
    std::vector<std::string> resulta = splitGroups(a);
    for (int i = 0; i < resulta.size(); i++)
        std::cout << resulta[i] << std::endl;
    std::cout << std::endl;

    std::cout << b << ":" << std::endl;
    std::vector<std::string> resultb = splitGroups(b);
    for (int i = 0; i < resultb.size(); i++)
        std::cout << resultb[i] << std::endl;
    std::cout << std::endl;

    std::cout << c << ":" << std::endl;
    std::vector<std::string> resultc = splitGroups(c);
    for (int i = 0; i < resultc.size(); i++)
        std::cout << resultc[i] << std::endl;
    std::cout << std::endl;

    std::cout << d << ":" << std::endl;
    std::vector<std::string> resultd = splitGroups(d);
    for (int i = 0; i < resultd.size(); i++)
        std::cout << resultd[i] << std::endl;
    std::cout << std::endl;

    while (1);
}