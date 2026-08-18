class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<2*nums.size(); i++)
        {
            res.push_back(nums[i%nums.size()]);
        }

        return res;
    }
};