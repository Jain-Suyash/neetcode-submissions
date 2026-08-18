class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(auto s:strs)
        {
            int l=s.length();
            string t=to_string(l);
            res+=t+"#"+s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string temp="";
        int l=s.length(), i=0;

        while(i<l)
        {
            string p="";
            temp="";
            while(s[i] != '#')
            {
                p+=s[i++];
            }
            i++;
            int len=stoi(p);
            while(len)
            {
                temp+=s[i++];
                len--;
            }
            res.push_back(temp);
        }

        return res;
    }
};
