#pragma once





struct Block
{
public:
    bool HasNum(int num)
    {
        for(int i = 0; i < 9; ++i)
        {
            if(*m_cells[i] == num)
                return true;
        }
        return false;
    }

    void PushBack(int* p_val)
    {
        m_cells[count] = p_val;
        ++count;
    }

    int operator[] (int index)
    {
        return *m_cells[index];
    }

private:
    int* m_cells[9];
    int count = 0;
};

class SudokuBoard
{
public:
    SudokuBoard();

    void Init(int cells[81]);

    void Set(int num, int index) { m_cells[index] = num; }

    int Get(int index) { return m_cells[index]; }

    Block& GetRow(int row) { return m_rows[row]; }
    Block& GetCol(int col) { return m_cols[col]; }
    Block& GetBox(int box) { return m_boxes[box]; }
    int* GetCells() { return m_cells; }

private:
    int m_cells[81];
    Block m_rows[9];
    Block m_cols[9];
    Block m_boxes[9];

private:
    void initMembers();
};

SudokuBoard::SudokuBoard()
{
    initMembers();
}

void SudokuBoard::Init(int cells[81])
{
    for(int i = 0; i < 81; ++i)
    {
        m_cells[i] = cells[i];
    }
}

void SudokuBoard::initMembers()
{
    for(int y = 0; y < 9; ++y)
    {
        for(int x = 0; x < 9; ++x)
        {
            m_rows[y].PushBack( &m_cells[y*9 + x] );
            m_cols[x].PushBack( &m_cells[y*9 + x] );
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
                    m_boxes[i*3 + j].PushBack( &m_cells[i*27+y*9+j*3+x] );
                }
            }
        }
    }
}