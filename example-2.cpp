#include "machine-engine.h"
#include <iostream>

enum States
{
    Up,
    Down
};

int main()
{
    MachineEngine<States, States, States> machineState;

    machineState.setCurrentState(Up);
    machineState.setState(Up, {Up, {{Down, Down}}});
    machineState.setState(Down, {Down, {{Up, Up}}});

    int input;

    while (true)
    {
        switch (machineState.getCurrentState().output)
        {
        case Up:
            std::cout << "up" << std::endl;
            break;
        case Down:
            std::cout << "down" << std::endl;
            break;
        }

        std::cin >> input;

        machineState.next((States)input);
    }
}