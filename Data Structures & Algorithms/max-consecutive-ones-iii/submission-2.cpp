class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, n=nums.size(), res=0, numOfZeroes=0;

        while(r<n)
        {
            if(nums[r] == 0)
                numOfZeroes++;

            if(numOfZeroes>k)
            {
                if(nums[l]==0)
                    numOfZeroes--;
                l++;
            }
            else
            {
                res=max(res, r-l+1);
            }
            r++;
        }

        return res;
    }
};