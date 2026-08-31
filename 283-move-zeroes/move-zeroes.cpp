class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int m = nums.size();
        int j = 0;

        for(int i=0 ; i<m ; i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};