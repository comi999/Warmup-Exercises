#include <iostream>
#include <vector>

typedef std::vector<std::vector<char>> OthelloBoardState;

struct GridVector
{
    int direction;
    int count;
};



bool CheckRay(int x, int y, int rotation, const OthelloBoardState& grid, char player, GridVector& vector)
{
    bool foundValidMove = false;
    bool foundOtherPlayer = false;
    char piece = 0;

    int dirX = 0;
    int dirY = 0;

    

    for (int i = 0; i < 8; i++)
    {
        //piece = GetPiece(x + i * dirX, y + i * dirY, grid);
        if (piece == player && foundOtherPlayer)
        {
            vector.direction = 2 * rotation;
            return true;
        }
        else if (player == 'W' && piece == 'B')  foundOtherPlayer = true;
        else if (player == 'B' && piece == 'W') foundOtherPlayer = true;
    }

    return false;
}

bool CheckUPRay(int x, int y, int rotation, const OthelloBoardState& grid, char player, GridVector& vector)
{
    bool foundValidMove = false;
    bool foundOtherPlayer = false;
    char piece = 0;

    int dirX = 0;
    int dirY = 0;

    if (rotation == 0) dirX = 0, dirY = -1;
    else if (rotation == 1) dirX = -1, dirY = 0;
    else if (rotation == 2) dirX = 0, dirY = 1;
    else if (rotation == 3) dirX = 1, dirY = 0;

    for (int i = 1; i < 8; i++)
    {
        piece = GetPiece(x + i * dirX, y + i * dirY, grid);
        if (piece == player && foundOtherPlayer)
        {
            vector.direction = 2 * rotation + 1;
            return true;
        }
        else if (player == 'W' && piece == 'B')  foundOtherPlayer = true;
        else if (player == 'B' && piece == 'W') foundOtherPlayer = true;
    }

    return false;
}

bool IsValidMove(char player, int x, int y, const OthelloBoardState& grid, GridVector& vector)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
        return false;

    bool TL = false;
    bool UP = false;

    for (int i = 0; i < 4; i++)
    {
        TL = CheckTLRay(x, y, i, grid, player, vector);
        if (TL) return TL;
        UP = CheckUPRay(x, y, i, grid, player, vector);
        if (UP) return UP;
    }

    return TL || UP;
}
OthelloBoardState MakeMove(char player, int x, int y, OthelloBoardState grid)
{
    // if the move was not valid, just return the origional...
    GridVector vector;
    if (IsValidMove(player, x, y, grid, vector) == false)
        return grid;
    
    int dirX, dirY;

    if (vector.direction == 0) dirX = -1, dirY = -1;
    if (vector.direction == 1) dirX =  0, dirY = -1;
    if (vector.direction == 2) dirX =  1, dirY = -1;
    if (vector.direction == 3) dirX =  1, dirY =  0;
    if (vector.direction == 4) dirX =  1, dirY =  1;
    if (vector.direction == 5) dirX =  0, dirY =  1;
    if (vector.direction == 6) dirX = -1, dirY =  1;
    if (vector.direction == 7) dirX = -1, dirY =  0;

    vector.count = 0;
    char piece;
    for (int i = 1; i < 8; i++)
    {
        piece = GetPiece(x + i * dirX, y + i * dirY, grid);
        if (player == 'W')
        {
            if (piece != 'W') vector.count++;
            else break;
        }
        if (player == 'B') 
        {
            if (piece != 'B') vector.count++;
            else break;
        }
    }

    for (int i = 0; i < vector.count; i++)
    {

    }

    return grid;
}

int main(int argc, char** argv)
{
    OthelloBoardState state1 =
    {//   0    1    2    3    4    5    6    7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', ' ', 'W', 'B', ' ', ' ', ' '}, // 3
        {' ', ' ', ' ', 'B', 'W', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
    };
    auto ShouldBe = [](auto result, auto expected) {
        std::cout << (result == expected ? "\033[32m [PASS]" : "\033[31m [FAIL]") << "\033[0m" << std::endl;
    };
    ShouldBe(IsValidMove('B', 5, 4, state1), true); // true
    ShouldBe(IsValidMove('B', 2, 4, state1), false); // false
    ShouldBe(IsValidMove('B', 3, 2, state1), true); // true
    ShouldBe(IsValidMove('B', 3, 5, state1), false); // false
    ShouldBe(IsValidMove('B', 5, 5, state1), false); // false
    ShouldBe(IsValidMove('W', 5, 4, state1), false); // false
    ShouldBe(IsValidMove('W', 2, 4, state1), true); // true
    ShouldBe(IsValidMove('W', 3, 2, state1), false); // false
    ShouldBe(IsValidMove('W', 3, 5, state1), true); // true
    ShouldBe(IsValidMove('W', 5, 5, state1), false); // false
    OthelloBoardState state2 =
    {//   0    1    2    3    4    5    6    7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
        {' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', 'B', 'W', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', 'B', 'W', 'B', ' ', ' ', ' '}, // 3
        {' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
    };
    ShouldBe(IsValidMove('B', 2, 5, state2), true); // true
    ShouldBe(IsValidMove('B', 3, 5, state2), false); // false
    ShouldBe(IsValidMove('B', 4, 5, state2), true); // true
    ShouldBe(IsValidMove('B', 3, 1, state2), false); // false
    ShouldBe(IsValidMove('B', 4, 2, state2), true); // true
    ShouldBe(IsValidMove('B', 4, 1, state2), true); // true

    ShouldBe(IsValidMove('W', 2, 5, state2), false); // false
    ShouldBe(IsValidMove('W', 2, 0, state2), true); // true
    ShouldBe(IsValidMove('W', 3, 1, state2), false); // false
    while (1);
    return 0;
}