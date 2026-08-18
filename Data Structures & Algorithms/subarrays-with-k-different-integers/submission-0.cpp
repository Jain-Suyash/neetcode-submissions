class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }

private:
    int helper(vector<int> &nums, int k)
    {
        if (k <= 0)
            return 0;

        unordered_map<int, int> mp;
        int l = 0, r = 0, cnt = 0;

        while (r < nums.size())
        {
            mp[nums[r]]++;

            while (mp.size() > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }

            if (mp.size() <= k)
                cnt += r - l + 1;
            
            r++;
        }

        return cnt;
    }
};