class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int T = 0; T <= amount; T++) {
                int notTake = 0 + dp[ind - 1][T];
                int take = INT_MAX;
                if (T >= coins[ind]) take = 1 + dp[ind][T - coins[ind]];
                dp[ind][T] = min(take, notTake);
            }
        }

        int res = dp[n - 1][amount];
        return res >= 1e9 ? -1 : res;
    }
};
