class Solution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid, res = INT16_MAX;

        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[low] <= nums[high]) {
                res = min(res, nums[low]);
                break;
            }
            if (nums[low] <= nums[mid]) {
                res = min(res, nums[low]);
                low = mid + 1;
            } else {
                res = min(res, nums[mid]);
                high = mid - 1;
            }
        }

        return res;
    }
};