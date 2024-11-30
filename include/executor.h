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

    void DoCommands(string commands)
    {
        is = 0;
        for (char command : commands) {
            if (!IsFast(command)) {
                switch (command) {
                case 'M':
                    MoveForward();
                    break;
                case 'L':
                    TurnLeft();
                    break;
                case 'R':
                    TurnRight();
                    break;
                }
            } else {
                switch (command) {
                case 'M':
                    MoveForward();
                    MoveForward();
                    break;
                case 'L':
                    MoveForward();
                    TurnLeft();
                    break;
                case 'R':
                    MoveForward();
                    TurnRight();
                    break;
                }
            }
        }
    }

private:
    int32_t x, y;
    Direction heading;
    bool is;

    bool IsFast(char cmd)
    {
        if (is == 0 && cmd == 'F') {
            is = 1;
        } else if (is == 1 && cmd == 'F') {
            is = 0;
        }
        return is;
    }

    void MoveForward()
    {
        switch (heading) {
        case N:
            ++y;
            break;
        case S:
            --y;
            break;
        case E:
            ++x;
            break;
        case W:
            --x;
            break;
        }
    }

    void TurnLeft()
    {
        switch (heading) {
        case N:
            heading = W;
            break;
        case S:
            heading = E;
            break;
        case E:
            heading = N;
            break;
        case W:
            heading = S;
            break;
        }
    }

    void TurnRight()
    {
        switch (heading) {
        case N:
            heading = E;
            break;
        case S:
            heading = W;
            break;
        case E:
            heading = S;
            break;
        case W:
            heading = N;
            break;
        }
    }
};