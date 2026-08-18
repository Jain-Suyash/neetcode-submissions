class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0, r=0, n=s.size(), res=0, sum=0;

        if(n==1)
            return 1;

        while(r<n)
        {
            sum=r-l;
            while(!mp[s[r]] && r<n)
            {
                mp[s[r]]++;
                r++;
                sum++;
            }
            // cout<<"Sum "<<sum<<endl;
            res=max(sum, res);

            while(s[l] != s[r])
            {
                mp[s[l]]--;
                l++;
            }
            mp[s[l]]--; l++; 
        }

        return res;
    }
};
