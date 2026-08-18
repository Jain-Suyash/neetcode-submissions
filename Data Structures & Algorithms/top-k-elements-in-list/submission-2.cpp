class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num:nums)
        {
            mp[num]++;
        }

        int n=nums.size();
        vector<vector<int>> vec(n+1);

        for(auto it:mp)
        {
            vec[it.second].push_back(it.first);
        }

        vector<int> res;
        int i=n;
        while(k)
        {
            if(vec[i].size())
            {
                int j=0;
                while(j<vec[i].size() && k)
                {
                    res.push_back(vec[i][j++]);
                    k--;
                }
            }
            i--;
        }

        return res;
    }
};
