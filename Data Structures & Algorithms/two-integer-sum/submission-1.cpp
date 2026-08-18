class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(auto i=0; i<nums.size(); i++)
        {
            mp[nums[i]]=i;
        }

        vector<int> vec;
        int targetSum;
        for(auto i=0; i<nums.size(); i++)
        {
            if(vec.size() == 1 && targetSum==nums[i])
            {
                vec.push_back(i);
                break;
            }
            if(vec.size() == 0 && mp[target-nums[i]]>i)
            {
                vec.push_back(i);
                targetSum=target-nums[i];
            }
        }
        return vec;
    }
};
