#include <map>

#pragma once

template <typename States, typename Input, typename Output>
class MachineEngine
{
    struct State
    {
        Output output;
        std::map<Input, States> next;
    };

    States currentState;

    std::map<States, State> machineEngine;

public:
    void setCurrentState(States state)
    {
        this->currentState = state;
    }

    void setState(States state, State transition)
    {
        machineEngine[state] = {
            transition.output,
            transition.next};
    }

    void next(Input input)
    {
        auto it = this->machineEngine[this->currentState].next.find(input);

        if (it == this->machineEngine[this->currentState].next.end())
        {
            return;
        }

        this->currentState = this->machineEngine[this->currentState].next[input];
    }

    State getCurrentState()
    {
        return this->machineEngine[this->currentState];
    }
};