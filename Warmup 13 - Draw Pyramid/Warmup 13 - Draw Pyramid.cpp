#include <iostream>

void print_row(int centre, int radius)
{
    int outside = centre - radius;
    for (int i = 0; i < outside; i++)
        std::cout << " ";
    for (int i = 0; i < 2 * radius + 1; i++)
        std::cout << "*";
    for (int i = 0; i < outside; i++)
        std::cout << " ";
}

void print_pyramid(int height)
{
    int sign = signbit((float)height);
    int increment = sign * -1 + (1 - sign) * 1;
    for (int i = 0; i < increment * height; i++)
    {
        print_row(increment * height, increment * i - sign * (height + 1));
        std::cout << std::endl;
    }
    
}

int main(int argc, char** argv)
{
    std::cout << "=======================================" << std::endl;
    print_pyramid(6);
    std::cout << "=======================================" << std::endl;
    print_pyramid(7);
    std::cout << "=======================================" << std::endl;
    print_pyramid(-1);
    std::cout << "=======================================" << std::endl;
    print_pyramid(-6);

    while (1);
}