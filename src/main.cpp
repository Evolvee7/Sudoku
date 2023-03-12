#include "SudokuSolver.hpp"
#include "SudokuValidator.hpp"
#include "SudokuLoader.hpp"
#include "Timer.hpp"

#include <iostream>
#include <string>



void print(int board[81]);

int main()
{
    const char* BOARDS_DIR = "../assets/boards/";
    SudokuValidator validator;
    SudokuLoader loader;
    SudokuSolver solver;

    Timer timer;

    int board[81]{};

    char ans = ' ';

    while(ans != 'q')
    {
        std::cout << "\nChoose one:\n";
        std::cout << "g - generate sudoku\n";
        std::cout << "l - load sudoku\n";
        std::cout << "p - print sudoku\n";
        std::cout << "s - solve sudoku\n";
        std::cout << "v - validate sudoku\n";
        std::cout << "q - quit\n";
        std::cout << "Your answer: ";

        std::string input;
        std::cin >> input;
        ans = input[0];

        switch(ans)
        {
            case 'g':   // generate sudoku
            {
                break;
            }
            case 'l':   // load sudoku
            {
                std::string path;
                std::cout << "Enter path: ";
                std::cin >> path;

                path = BOARDS_DIR + path;
                if(loader.Load(path, board))
                    std::cout << "\n>> Sudoku has been loaded successfully <<\n";
                else
                    std::cout << "\n>> Could not load sudoku <<\n";
                break;
            }
            case 'p':   // print sudoku
            {
                print(board);
                break;
            }
            case 's':   // solve sudoku
            {
                timer.Start();
                solver.Solve(board);
                std::cout << ">> Sudoku was solved in " << timer.GetUs() << " us <<\n";
                break;
            }
            case 'v':   // validate sudoku
            {
                if(validator.Valid(board))
                    std::cout << "\n>> Given sudoku is valid <<\n";
                else
                    std::cout << "\n>> Given sudoku is NOT valid <<\n";
                break;
            }
            case 'q':   // quit
            {
                std::cout << "Bye!\n";
                break;
            }
        }


    }

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