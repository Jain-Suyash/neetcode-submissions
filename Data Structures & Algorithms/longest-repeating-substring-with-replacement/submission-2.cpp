class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int res = 0, l = 0, r = 0, changes = 0, maxFreq = 0;

        while (r < s.size())
        {
            mp[s[r]]++;

            maxFreq = max(maxFreq, mp[s[r]]);
            changes = (r - l + 1) - maxFreq;

            if (changes <= k)
                res = max(res, r - l + 1);
            else {
                mp[s[l]]--;
                maxFreq = 0;
                l++;
            }
            r++;
        }

        return res;
    }
};
