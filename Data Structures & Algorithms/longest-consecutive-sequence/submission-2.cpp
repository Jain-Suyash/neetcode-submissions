class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i] - 1) == 0) {
                int startNo = nums[i] + 1, len = 1;
                while (mp.count(startNo)) {
                    startNo++;
                    len++;
                }
                res = max(res, len);
            }
        }

        return res;
    }
};
