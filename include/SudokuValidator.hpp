#pragma once





class SudokuValidator
{
public:
    bool Valid(int cells[81]);
};

bool SudokuValidator::Valid(int cells[81])
{
    // validate rows
    for(int y = 0; y < 9; ++y)
    {
        bool exist[9]{false};
        for(int x = 0; x < 9; ++x)
        {
            int index = y*9 + x;
            if(cells[index] == 0)
                continue;
            
            int i = cells[index]-1;
            if(exist[i] == true)
                return false;
            exist[i] = true;
        }
    }

    // validate columns
    for(int x = 0; x < 9; ++x)
    {
        bool exist[9]{false};
        for(int y = 0; y < 9; ++y)
        {
            int index = y*9 + x;
            if(cells[index] == 0)
                continue;
            
            int i = cells[index]-1;
            if(exist[i] == true)
                return false;
            exist[i] = true;
        }
    }

    // validate boxes
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            bool exist[9]{false};
            for(int y = 0; y < 3; ++y)
            {
                for(int x = 0; x < 3; ++x)
                {
                    int index = i*27+y*9+j*3+x;
                    if(cells[index] == 0)
                        continue;
                    
                    int i = cells[index]-1;
                    if(exist[i] == true)
                        return false;
                    exist[i] = true;
                }
            }
        }
    }
    
    return true;
}