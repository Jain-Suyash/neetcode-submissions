class Solution {
   private:
    int f(int ind, int prevInd, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;
        if (dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];
        int notTake = 0 + f(ind + 1, prevInd, nums, n, dp);
        int take = INT_MIN;
        if (prevInd == -1 || nums[ind] > nums[prevInd]) take = 1 + f(ind + 1, ind, nums, n, dp);
        return dp[ind][prevInd + 1] = max(take, notTake);
    }

   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, nums.size(), dp);
    }
};
