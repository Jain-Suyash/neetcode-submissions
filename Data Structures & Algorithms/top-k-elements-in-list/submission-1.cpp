class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num:nums)
        {
            mp[num]++;
        }

        map<int, vector<int>> temp;
        vector<int> res;

        for(auto it: mp)
        {
            temp[it.second].push_back(it.first);
        }

        vector<int> vec;
        for(auto it=temp.rbegin(); k>0; it++)
        {
            vec=it->second;
            for(int i=0; i<vec.size() && k>0; i++)
            {
                res.push_back(vec[i]);
                k--;
            }
        }
        return res;
    }
};
