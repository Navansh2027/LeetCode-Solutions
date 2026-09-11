class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeros = 0;
        int ans = 0;

        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 0)
                zeros++;

            while(zeros > 1)
            {
                if(nums[left] == 0)
                    zeros--;

                left++;
            }
            ans = max(ans, i - left);
        }

        return ans;
    }
};