class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 1) 
        {
            unordered_map<int, int> freq;

            for (int x : nums) 
            {
                freq[x]++;
            }

            int ans = -1;

            for (auto& [x, count] : freq) 
            {
                if (count == 1) 
                {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        if (k == n) 
        {
            return *max_element(nums.begin(), nums.end());
        }

        int ans = -1;

        bool firstUnique = true;

        for (int i = 1; i < n; i++) 
        {
            if (nums[i] == nums[0]) 
            {
                firstUnique = false;
                break;
            }
        }

        if (firstUnique) 
        {
            ans = max(ans, nums[0]);
        }

        bool lastUnique = true;

        for (int i = 0; i < n - 1; i++) 
        {
            if (nums[i] == nums[n - 1]) 
            {
                lastUnique = false;
                break;
            }
        }

        if (lastUnique) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};