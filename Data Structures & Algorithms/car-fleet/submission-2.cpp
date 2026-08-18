class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < position.size(); i++) {
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.rbegin(), vec.rend());

        vector<double> st;
        for (auto v : vec) {
            st.push_back((double)(target - v.first) / v.second);
            while (st.size() >= 2 && st.back() <= st[st.size() - 2]) st.pop_back();
        }

        return st.size();
    }
};
