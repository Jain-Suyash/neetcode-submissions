class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, n=nums.size(), res=0, numOfZeroes=0, i=0;

        while(r<n)
        {
            if(nums[r] == 0)
            {
                numOfZeroes++;
            }

            if(numOfZeroes>k)
            {
                // cout<<l<<" "<<r<<endl;
                res=max(res, r-l);

                while(nums[l] != 0)
                {
                    l++;
                }
                l++;
                numOfZeroes--;
            }
            r++;
        }
        res=max(res, r-l);

        return res;
    }
};