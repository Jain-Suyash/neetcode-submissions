class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0, r = 0, sum = 0, cnt1 = 0;

        while (r < nums.size())
        {
            sum += nums[r];

            while (sum > goal)
            {
                sum -= nums[l++];
            }

            cnt1 += r - l + 1;
            r++;
        }

        int cnt2 = 0;
        l = 0, r = 0, sum = 0, goal--;
        if (goal >= 0)
        {
            while (r < nums.size())
            {
                sum += nums[r];

                while (sum > goal)
                {
                    sum -= nums[l++];
                }

                cnt2 += r - l + 1;
                r++;
            }
        }

        return cnt1 - cnt2;
    }
};