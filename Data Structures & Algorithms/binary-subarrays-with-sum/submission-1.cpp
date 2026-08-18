class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return helper(nums, goal) - helper(nums, goal - 1);
    }

    private:
        int helper(vector<int>& nums, int target) {
            if(target < 0) return 0;

            int l = 0, r = 0, sum = 0, cnt = 0;

            while (r < nums.size())
            {
                sum += nums[r];

                while (sum > target)
                {
                    sum -= nums[l++];
                }

                cnt += r - l + 1;
                r++;
            }

            return cnt;
        }
};