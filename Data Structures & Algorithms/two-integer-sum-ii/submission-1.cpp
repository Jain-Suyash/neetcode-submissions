class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;

        while (l < r && r < n)
        {
            if (numbers[l] + numbers[r] == target)
            {
                return {l + 1, r + 1};
            }

            if (l < r && numbers[l] < target - numbers[r])
            {
                l++;
            }

            if (numbers[l] + numbers[r] > target)
            {
                r--;
            }
        }
    }
};
