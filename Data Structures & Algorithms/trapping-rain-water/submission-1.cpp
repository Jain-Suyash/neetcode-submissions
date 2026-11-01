class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pge(n);
        pge[0] = 0;
        for (int i = 1; i < n; i++) {
            pge[i] = max(pge[i - 1], height[i - 1]);
        }

        vector<int> nge(n);
        nge[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            nge[i] = max(nge[i + 1], height[i + 1]);
        }

        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            int water = min(nge[i], pge[i]) - height[i];
            if (water > 0) res += water;
        }

        return res;
    }
};
