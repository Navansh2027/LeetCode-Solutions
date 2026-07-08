class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        long long MOD = 1e9 + 7;
        
        vector<long long> sumD(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<long long> p(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        
        for (int i = 1; i <= n; i++) 
        {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        for (int i = 1; i <= n; i++) 
        {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cnt[i] = cnt[i - 1] + (d > 0 ? 1 : 0);
            
            if (d > 0) {
                p[i] = (p[i - 1] * 10 + d) % MOD;
            } else {
                p[i] = p[i - 1]; 
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) 
        {
            int l = q[0], r = q[1];
            
            int n0 = cnt[r + 1] - cnt[l];
            long long sd = sumD[r + 1] - sumD[l];
            
            long long x = (p[r + 1] - (p[l] * pow10[n0]) % MOD + MOD) % MOD;
            
            ans.push_back((x * sd) % MOD);
        }
        
        return ans;
    }
};