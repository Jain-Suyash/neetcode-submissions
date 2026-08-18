class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>  result;
        unordered_map<string, string> mp;
        unordered_map<string, int> mpCount;
        string t;

        for(auto s:strs)
        {
            t=s;
            sort(t.begin(), t.end());
            if(mpCount[t])
            {
                for(int i=0; i<result.size(); i++)
                {
                    auto it=find(result[i].begin(), result[i].end(), mp[t]);
                    if(it != result[i].end())
                        result[i].push_back(s);
                }
            }
            else
            {
                mp[t]=s;
                mpCount[t]++;
                result.push_back({s});
            }
        }
        return result;
    }
};
