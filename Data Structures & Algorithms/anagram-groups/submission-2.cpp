class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>  temp;

        for(auto s:strs)
        {    
            int arr[26]={0};
            for(char ch:s)
            {
                arr[ch-'a']++;
            }
            string key=to_string(arr[0]);
            for(int i=1; i<26; i++)
            {
                key+=','+to_string(arr[i]);
            }
            temp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto it: temp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};
