class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        int ans = 0;
        int zeros = 0;

        for(int i=0 ; i<n ; i++)
        {
            if(nums[i] == 0)
                zeros++;

            while(zeros > k)
            {
                if(nums[left] == 0)
                    zeros--;

                left++;    
            }    
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};