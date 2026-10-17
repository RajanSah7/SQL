class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int count=0,i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(nums[i]==nums[j])
                {
                    count = count + 1;
                }
            }
            if(count == 1)
            {
                return nums[i];
            }
            count =0;
        }
        return 0;
    }
};