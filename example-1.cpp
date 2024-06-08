#include <iostream>
#include <map>

enum InputCard
{
    cardIn,
    done,
    broken,
    fixed
};

enum CardMachineState
{
    Idle,
    Working,
    OutOfService
};

template <typename T, typename O>
struct State
{
    T output;
    std::map<O, T> next;
};

int main()
{
    std::map<CardMachineState, State<CardMachineState, InputCard>> machineState;

    machineState[Idle] = {
        Idle,
        {{cardIn, Working},
         {broken, OutOfService}}};

    machineState[Working] = {
        Working,
        {{done, Idle}}};

    machineState[OutOfService] = {
        OutOfService,
        {{fixed, Idle}}};

    int input;
    CardMachineState currentState = Idle;

    while (true)
    {
        CardMachineState state = machineState[currentState].output;
        switch (state)
        {
        case Idle:
            std::cout << "iddle" << std::endl;
            break;
        case Working:
            std::cout << "working" << std::endl;
            break;
        case OutOfService:
            std::cout << "out of service" << std::endl;
            break;
        default:
            break;
        }

        std::cin >> input;
        auto it = machineState[currentState].next.find((InputCard)input);
        if (it == machineState[currentState].next.end())
        {
            continue;
        }
        currentState = machineState[currentState].next[(InputCard)input];
    }
}