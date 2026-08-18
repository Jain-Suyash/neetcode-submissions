class Solution {
public:

    string encode(vector<string> &strs)
    {
        string res = "";

        for (auto s : strs)
        {
            res += to_string(s.size()) + '#' + s;
        }

        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int i = 0;

        while (i < s.size())
        {
            string l = "";
            while (s[i] != '#')
            {
                l += s[i++];
            }
            int len = stoi(l);
            
            string t = "";
            i++;
            while(len)
            {
                t += s[i++];
                len--;
            }
            res.push_back(t);
        }

        return res;
    }
};
