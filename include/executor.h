#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Executor
{
public:
    enum Direction { N = 'N', S = 'S', E = 'E', W = 'W' };

    void GetPositionAndHeading(int32_t& x, int32_t& y, char& heading) const
    {
        x = this->x;
        y = this->y;
        heading = this->heading;
    }

    void Init(int32_t x = 0, int32_t y = 0, char heading = 'N')
    {
        this->x = x;
        this->y = y;
        this->heading = static_cast<Direction>(heading);
    }

    void Move(string commands)
    {
        for (char command : commands) {
            if (is) {
                switch (command) {
                case 'M':
                    MoveForward{}.DoCommands(*this);
                    MoveForward{}.DoCommands(*this);
                    break;
                case 'L':
                    MoveForward{}.DoCommands(*this);
                    TurnLeft{}.DoCommands(*this);
                    break;
                case 'R':
                    MoveForward{}.DoCommands(*this);
                    TurnRight{}.DoCommands(*this);
                    break;
                case 'F':
                    IsFast{}.DoCommands(*this);
                    break;
                }
            } else {
                switch (command) {
                case 'M':
                    MoveForward{}.DoCommands(*this);
                    break;
                case 'L':
                    TurnLeft{}.DoCommands(*this);
                    break;
                case 'R':
                    TurnRight{}.DoCommands(*this);
                    break;
                case 'F':
                    IsFast{}.DoCommands(*this);
                    break;
                }
            }
        }
    }

private:
    int32_t x, y;
    Direction heading;
    bool is = 0;

    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoCommands(Executor& executor) = 0;
    };

    class IsFast final : public ICommand
    {
    public:
        void DoCommands(Executor& executor) override
        {
            executor.is = !executor.is;
        }
    };

    class MoveForward final : public ICommand
    {
    public:
        void DoCommands(Executor& executor) override
        {
            switch (executor.heading) {
            case N:
                ++executor.y;
                break;
            case S:
                --executor.y;
                break;
            case E:
                ++executor.x;
                break;
            case W:
                --executor.x;
                break;
            }
        }
    };

    class TurnLeft final : public ICommand
    {
    public:
        void DoCommands(Executor& executor) override
        {
            switch (executor.heading) {
            case N:
                executor.heading = W;
                break;
            case S:
                executor.heading = E;
                break;
            case E:
                executor.heading = N;
                break;
            case W:
                executor.heading = S;
                break;
            }
        }
    };

    class TurnRight final : public ICommand
    {
    public:
        void DoCommands(Executor& executor) override
        {
            switch (executor.heading) {
            case N:
                executor.heading = E;
                break;
            case S:
                executor.heading = W;
                break;
            case E:
                executor.heading = S;
                break;
            case W:
                executor.heading = N;
                break;
            }
        }
    };
};