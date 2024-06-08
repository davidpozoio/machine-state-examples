#include <map>
#include <iostream>

enum MyStates
{
    even,
    odd
};

template <typename States, typename Input, typename Output>
struct State
{
    Output output;
    std::map<Input, States> next;
};

int main()
{
    std::map<MyStates, State<MyStates, bool, bool>> machineState;

    machineState[even] = {
        true,
        {{true, odd},
         {false, even}}};

    machineState[odd] = {
        false,
        {{true, even},
         {false, odd}}};

    bool input;
    MyStates currenState = odd;

    while (true)
    {
        if (machineState[currenState].output)
        {
            std::cout << "even" << std::endl;
        }
        else
        {
            std::cout << "odd" << std::endl;
        }

        std::cin >> input;
        auto it = machineState[currenState].next.find(input);
        if (it == machineState[currenState].next.end())
        {
            continue;
        }

        currenState = machineState[currenState].next[input];
    }
}