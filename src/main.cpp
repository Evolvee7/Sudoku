#include "SudokuSolver.hpp"

#include <iostream>



void print(int board[81]);

int main()
{
    SudokuSolver solver;
    int board[81]{};

    board[0] = 5;
    board[1] = 7;

    print(board);

    solver.Solve(board);
    //std::cout << solver.Solutions(board) << std::endl;

    print(board);

    return 0;
}

void print(int board[81])
{
    std::cout << '\n';
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            std::cout << board[i*9 + j] << ' ';

            if(j == 2 || j ==5)
                std::cout << "| ";
        }
        std::cout << '\n';

        if(i == 2 || i == 5)
            std::cout << "------+-------+------\n";
    }
    std::cout << '\n';
}