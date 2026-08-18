class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;

        for(auto str:strs)
        {
            vector<int> arr(26);
            for(auto c:str)
            {
                arr[c-'a']++;
            }

            mp[arr].push_back(str);
        }

        vector<vector<string>> res;
        for(auto it:mp)
        {
            res.push_back(it.second);
        }   
        return res;
    }
};
