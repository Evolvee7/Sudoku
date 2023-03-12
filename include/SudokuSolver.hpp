#pragma once




class SudokuSolver
{
public:
    bool Solve(int cells[81]);
    int Solutions(int cells[81]);
    bool Unique(int cells[81]);

private:
    int* m_cells[81];
    int* m_rows[9][9];
    int* m_cols[9][9];
    int* m_boxes[9][9];

    int m_solutions;

    static constexpr int MAX_SOLUTIONS = 100;

private:
    void initMembers(int* cells);
    bool solve(int index);
    void solutions(int index);
    bool unique(int index);
    bool valid(int num, int index) const;
};

bool SudokuSolver::Solve(int cells[81])
{
    initMembers(cells);

    return solve(0);
}

int SudokuSolver::Solutions(int cells[81])
{
    initMembers(cells);

    m_solutions = 0;
    solutions(0);

    return m_solutions;
}

bool SudokuSolver::Unique(int cells[81])
{
    initMembers(cells);

    m_solutions = 0;

    return unique(0);
}

void SudokuSolver::initMembers(int* cells)
{
    for(int i = 0; i < 81; ++i)
    {
        m_cells[i] = &cells[i];
    }

    for(int y = 0; y < 9; ++y)
    {
        for(int x = 0; x < 9; ++x)
        {
            m_rows[y][x] = &cells[y*9 + x];
            m_cols[x][y] = &cells[y*9 + x];
        }
    }

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            for(int y = 0; y < 3; ++y)
            {
                for(int x = 0; x < 3; ++x)
                {
                    m_boxes[i*3 + j][y*3 + x] = &cells[i*27+y*9+j*3+x];
                }
            }
        }
    }
}

bool SudokuSolver::solve(int index)
{
    if(index >= 81)
        return true;
    else if(*m_cells[index] != 0)
        return solve(index + 1);
    else
    {
        for(int num = 1; num < 10; ++num)
        {   
            if(valid(num, index))
            {
                *m_cells[index] = num;

                if(solve(index + 1))
                    return true;
                *m_cells[index] = 0;
            }
        }
    }
    return false;
}

void SudokuSolver::solutions(int index)
{
    if(m_solutions >= MAX_SOLUTIONS)
        return;
    else if(index >= 81)
        ++m_solutions;
    else if(*m_cells[index] != 0)
        solutions(index + 1);
    else
    {
        for(int num = 1; num < 10; ++num)
        {   
            if(valid(num, index))
            {
                *m_cells[index] = num;

                solutions(index + 1);
            }
        }
        *m_cells[index] = 0;
    }
}

bool SudokuSolver::unique(int index)
{
    if(m_solutions > 1)
        return false;
    else if(index >= 81)
        ++m_solutions;
    else if(*m_cells[index] != 0)
        return unique(index + 1);
    else
    {
        for(int num = 1; num < 10; ++num)
        {   
            if(valid(num, index))
            {
                *m_cells[index] = num;

                return unique(index + 1);
            }
        }
        *m_cells[index] = 0;
    }
    return true;
}

bool SudokuSolver::valid(int num, int index) const
{
    int row = index/9;
    for(int i = 0; i < 9; ++i)
    {
        if(num == *m_rows[row][i])
            return false;
    }

    int col = index%9;
    for(int i = 0; i < 9; ++i)
    {
        if(num == *m_cols[col][i])
            return false;
    }

    int box = (index%9)/3 + (index/27)*3;
    for(int i = 0; i < 9; ++i)
    {
        if(num == *m_boxes[box][i])
            return false;
    }
    
    return true;
}