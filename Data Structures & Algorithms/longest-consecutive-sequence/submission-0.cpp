class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto n:nums)
        {
            mp[n]++;
        }

        int res=0, lookup;
        for(int i=0; i<nums.size(); i++)
        {
            int s=0;
            lookup=nums[i]++;
            while(mp[lookup])
            {
                lookup++;
                s++;
            }

            if(s>res)
                res=s;
        }

        return res;
    }
};
