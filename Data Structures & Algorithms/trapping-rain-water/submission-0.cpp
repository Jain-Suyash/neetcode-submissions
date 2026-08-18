class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = 0;
        maxRight[n - 1] = 0;
        int res = 0;

        for (int i = 1; i < n; i++)
        {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        }

        for (int i = 1; i < n - 1; i++)
        {
            int h = min(maxLeft[i], maxRight[i]) - height[i];
            if (h > 0)
                res += h;
        }

        return res;
    }
};
