class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";
        for (string s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            string temp = "";
            while (s[i] != '#') {
                temp += s[i++];
            }
            int size = stoi(temp);
            i++;

            temp = s.substr(i, size);
            res.push_back(temp);
            i += size;
        }

        return res;
    }
};
