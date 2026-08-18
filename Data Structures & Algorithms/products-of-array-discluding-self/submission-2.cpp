class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;
        vector<int> res;
        int product=nums[0];
        int n=nums.size();
        prefix.push_back(nums[0]);
        suffix.push_back(nums[n-1]);

        for(int i=1; i<n-1; i++)
        {
            product*=nums[i];
            prefix.push_back(product);
        }

        product=nums[n-1];
        for(int i=n-2; i>0; i--)
        {
            product*=nums[i];
            suffix.push_back(product);
        }

        res.push_back(suffix[n-2]);
        for(int i=1; i<n-1; i++)
        {
            res.push_back(prefix[i-1]*suffix[n-i-2]);
        }
        res.push_back(prefix[n-2]);

        return res;
    }
};
