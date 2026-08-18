class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (auto c : s1)
        {
            mp1[c]++;
        }

        int l = 0, r = 0;

        while (r < s2.size())
        {
            cout<<l<<" "<<r<<endl;
            mp2[s2[r]]++;

            while (mp2.size() > mp1.size() || r-l+1 > s1.size())
            {
                mp2[s2[l]]--;
                if (mp2[s2[l]] == 0)
                    mp2.erase(s2[l]);
                l++;
            }

            if (mp1 == mp2)
                return true;

            r++;
        }

        return false;
    }
};
