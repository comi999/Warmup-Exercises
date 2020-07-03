#include <iostream>


#include <chrono>
#include <string>
template <typename T>
double FunctionTimer(T p)
{
    auto start = std::chrono::steady_clock::now();
    p();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = (end - start);
    return elapsed_seconds.count();
}

int DoSomeLongRunningThing()
{
    int counter = 0;
    for (int i = 0; i < 9000; i++)
    {
        std::cout << i << std::endl;
        counter += 1;
    }
    return counter;
}
int main(int argc, char** argv)
{
    // For todays exercise, we want to record how much time it takes to "do some work"
    // you will need to:
    // - get a start time
    // - get an end time
    // - subtract the difference and print the result in miliseconds.
    // Once you've done that... how might you make your code easily re-usable.
    // --
    std::cout << "Hello World" << std::endl;
    // --
    std::cout << "TODO" << std::endl;
    // TODO: output to console - number of miliseconds it took to print "Hello World" above


    // --
    auto time = FunctionTimer(DoSomeLongRunningThing);
    char b[20];
    sprintf_s(b, "%.2f", time);
    // --
    std::cout << "Elapsed Time: " << b << std::endl;
    // TODO: output to console - number of miliseconds it took to took to call the above method
    while (1);
}