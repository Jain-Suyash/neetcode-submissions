class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], maxProd = 1, minProd = 1;

        for (auto num : nums) {
            int temp = maxProd * num;
            maxProd = max(max(maxProd * num, minProd * num), num);
            minProd = min(min(temp, minProd * num), num);
            res = max(res, maxProd);
        }

        return res;
    }
};
