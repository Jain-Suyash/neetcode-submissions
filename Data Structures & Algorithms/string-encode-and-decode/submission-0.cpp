class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(auto s:strs)
        {
            for(char c:s)
            {
                char c1=255-c;
                res+=c1;
            }
            res+="|";
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string temp="";

        for(char c:s)
        {
            if(c != '|')
            {
                char c1=255-c;
                temp+=c1;
            }
            else
            {
                res.push_back(temp);
                temp="";
            }
        }

        return res;
    }
};
