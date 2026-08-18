class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        res[n - 1] = -1;

        int maxi = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxi = max(maxi, arr[i + 1]);
            res[i] = maxi;
        }

        return res;
    }
};