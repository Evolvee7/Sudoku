#pragma once

#include <fstream>
#include <string>



class SudokuLoader
{
public:
    bool Load(std::string& path, int cells[81]);

private:
    bool validCharacters();
};

bool SudokuLoader::Load(std::string& path, int cells[81])
{
    std::ifstream ifstream(path, std::ios_base::in);

    if(!ifstream.is_open())
        return false;
    
    // TODO: VALIDATE HERE
    
    for(int i = 0; i < 81; ++i)
    {
        ifstream >> cells[i];
    }

    return true;
}