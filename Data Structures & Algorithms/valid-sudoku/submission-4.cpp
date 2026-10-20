class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int> mr, mc, mb;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int b = (r / 3) * 3 + c / 3;
                    string row = board[r][c] + to_string(r);
                    string col = board[r][c] + to_string(c);
                    string box = board[r][c] + to_string(b);
                    mr[row]++, mc[col]++, mb[box]++;

                    if (mr[row] > 1 || mc[col] > 1 || mb[box] > 1) return false;
                }
            }
        }

        return true;
    }
};
