class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> mp;
        unordered_map<string, int> mc;
        unordered_map<char, int> mb1;
        unordered_map<char, int> mb2;
        unordered_map<char, int> mb3;

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                char c=board[i][j];

                if(c !='.')
                {
                    if(++mp[c]>1) 
                        return false;
                        
                    if(j<3)
                    {
                        if(++mb1[c]>1)
                            return false;
                    }
                    else if(j<6)
                    {
                        if(++mb2[c]>1)
                            return false;
                    }
                    else
                    {
                        if(++mb3[c]>1)
                            return false;
                    }

                    //column logic
                    string col=to_string(j)+c;
                    if(++mc[col]>1)
                        return false;
                }            
            }

            if(i%3==2)
            {
                mb1.clear();
                mb2.clear();
                mb3.clear();
            }

            mp.clear();
        }

        return true;
    }
};
