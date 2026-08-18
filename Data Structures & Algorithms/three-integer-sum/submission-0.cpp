class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        set<vector<int>> st;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int target = -(nums[i] + nums[j]);
                if (mp.count(target) && mp[target] != i && mp[target] != j)
                {
                    vector<int> triplet = {nums[i], nums[j], target};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);
                }
            }
        }

        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
