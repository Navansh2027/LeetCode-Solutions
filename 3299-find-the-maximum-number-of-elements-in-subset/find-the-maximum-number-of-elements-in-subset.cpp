class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;
        
        if (cnt.count(1))
            ans = cnt[1] - (cnt[1] % 2 == 0);

        int mx = *max_element(nums.begin(), nums.end());

        for (auto &[x, _] : cnt) {

            if (x == 1)
                continue;

            long long cur = x;
            int len = 0;

            while (cur <= mx && cnt[cur] >= 2) {
                len += 2;
                cur = cur * cur;
            }

            if (cur <= mx && cnt[cur] == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};