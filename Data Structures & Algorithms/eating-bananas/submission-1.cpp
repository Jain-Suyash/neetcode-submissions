class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for (auto i : piles)
        {
            high = max(high, i);
        }

        int low = 1, res = high + 1, mid;

        while (low <= high)
        {
            mid = (low + high) / 2;

            int total = 0;
            for (auto bananas : piles)
            {
                total += (bananas + mid - 1) / mid;
                if(total > h) {
                    low = mid + 1;
                    break;
                }
            }
            if (total <= h)
            {
                res = min(res, mid);
                high = mid - 1;
            }
        }

        return res;
    }
};
