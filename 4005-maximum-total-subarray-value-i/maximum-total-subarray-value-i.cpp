class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minimum = nums[0];
        int maximum = nums[0];

        for(int num : nums)
        {
            if(num < minimum)
                minimum = num;
            if(num > maximum)
                maximum = num;    
        }

        long long diff = maximum - minimum;

        long long ans = diff * k;

        return ans;
    }
};