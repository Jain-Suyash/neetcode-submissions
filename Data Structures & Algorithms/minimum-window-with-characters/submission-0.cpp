class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = t.length(), sIdx = -1, minLen = 10000, cnt = 0;
        int l = 0, r = 0;
        vector<int> vec(256, 0);

        for (auto c : t)
        {
            vec[c]++;
        }

        while (r < s.size())
        {
            if (vec[s[r]] > 0)
                cnt++;
            vec[s[r]]--;

            while (cnt == m)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    sIdx = l;
                }

                vec[s[l]]++;
                if (vec[s[l]] > 0)
                    cnt--;
                l++;
            }

            r++;
        }

        if(sIdx == -1)
            return "";

        return s.substr(sIdx, minLen);
    }
};
