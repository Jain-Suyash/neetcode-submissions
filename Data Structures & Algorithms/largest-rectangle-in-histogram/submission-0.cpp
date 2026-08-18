class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = previousSmall(heights);
        vector<int> nse = nextSmall(heights);
        int res=0;

        for (int i = 0; i < heights.size(); i++) {
            res = max(res, (nse[i] - pse[i] - 1) * heights[i]);
        }

        return res;
    }

   private:
    vector<int> previousSmall(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    vector<int> nextSmall(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }
};
