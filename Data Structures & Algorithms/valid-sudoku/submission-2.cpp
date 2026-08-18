class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int> mr;
        unordered_map<string, int> mc;
        unordered_map<string, int> mb;

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                char c=board[i][j];

                if(c !='.')
                {
                    int b=(i/3)*3+j/3;
                    string row=to_string(i)+c;
                    string col=to_string(j)+c;
                    string box=to_string(b)+c;
                    mr[row]++; 
                    mc[col]++;
                    mb[box]++;

                    if(mr[row]>1 || mc[col]>1 || mb[box]>1)
                        return false;
                }            
            }
        }

        return true;
    }
};
