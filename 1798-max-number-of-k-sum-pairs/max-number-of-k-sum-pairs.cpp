class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        int right = nums.size() - 1;

        sort(nums.begin(), nums.end());

        while(left < right)
        {
            int curr_sum = nums[left] + nums[right];

            if(curr_sum == k)
            {
                count++;
                left++;
                right--;
            }
            else if(curr_sum < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return count;
    }
};