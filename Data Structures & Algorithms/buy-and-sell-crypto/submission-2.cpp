class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int res = 0, start = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[start])
                res = max(res, prices[i] - prices[start]);
            else
                start = i;
        }

        return res;
    }
};
