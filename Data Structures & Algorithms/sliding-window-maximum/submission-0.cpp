class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            int maxNum = nums[i];

            for (int j = i + 1; j < i + k; j++)
            {
                maxNum = max(nums[j], maxNum);
            }
            res.push_back(maxNum);
        }

        return res;
    }
};
