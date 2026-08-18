class Solution {
   private:
    int helper(vector<int>& nums, int p) {
        int cnt = 1, sum = 0;
        for (int n : nums) {
            if (sum + n <= p)
                sum += n;
            else {
                cnt++;
                sum = n;
            }
        }

        return cnt;
    }

   public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        for (int n : nums) {
            low = max(low, n);
            high += n;
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            if (helper(nums,mid) > k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};