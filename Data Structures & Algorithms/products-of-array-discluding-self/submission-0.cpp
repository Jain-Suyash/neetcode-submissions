class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int product=1;
        int numOfZeroes=0;

        for(auto num:nums)
        {
            if(num==0)
                numOfZeroes++;
            product*=num;
        }

        if(numOfZeroes==1)
        {
            product=1;
            for(auto num:nums)
            {
                if(num!=0)
                    product*=num;
            }
        }

        for(auto num:nums)
        {
            if(numOfZeroes==0)
                res.push_back(product/num);
            else if(numOfZeroes==1)
            {
                if(num!=0)
                    res.push_back(0);
                else
                    res.push_back(product);
            }
            else
                res.push_back(0);
        }

        return res;
    }
};
