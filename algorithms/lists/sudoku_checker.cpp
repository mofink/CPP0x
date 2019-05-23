//https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //check rows
        for (auto& row: board)
        {
            std::set<char> container;
            for (auto& num: row)
            {
                if (container.find(num) != container.end())
                {
                    return false;
                }
                else
                {
                    if (num != '.')
                    {
                        container.emplace(num);
                    }
                }
            }
        }
        
        //check cols
        for (int i = 0; i < 9; ++i)
        {
            std::set<char> container;
            for (int j = 0; j < 9; ++j)
            {
                char num = board[j][i];
                
                if (container.find(num) != container.end())
                {
                    return false;
                }
                else
                {
                    if (num != '.')
                    {
                        container.emplace(num);
                    }
                }
            }
        }
        
        //check cells
        for (int M = 0; M < 9; M += 3)
        {
            for (int N = 0; N < 9; N+=3)
            {
                std::set<char> container;
                for (int i = 0 + M; i < 3 + M; ++i)
                {
                    for (int j = 0 + N; j < 3 + N; ++j)
                    {
                        char num = board[i][j];
                        if (container.find(num) != container.end())
                        {
                            return false;
                        }
                        else
                        {
                            if (num != '.')
                            {
                                container.emplace(num);
                            }
                        }
                    }
                }
            }
        }
            
        return true;
    }
};
