class Solution {
   public:
    int lengthOfLastWord(string s) {
        int res = 0, n = s.size();
        int i = n - 1;
        while (s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') {
            res++;
            i--;
        }

        return res;
    }
};