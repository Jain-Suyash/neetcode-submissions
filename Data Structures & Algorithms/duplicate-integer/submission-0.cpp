class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int n: nums)
        {
            if(++mp[n] > 1)
            {
                return true;
            }
        }
        return false;
    }
};