class Solution {
public:
    int subsequencePairCount(vector<int>& nums) 
    {
        const int MOD = 1e9 + 7;

        int max_val = 0;
        for(int x : nums)
        {
            if(x > max_val) max_val = x; 
        }

        vector<vector<int>> gcd_table(max_val + 1, vector<int>(max_val+1));
        for(int i = 0 ; i<= max_val ; ++i)
        {
            for(int j=0 ; j <= max_val ; ++j)
            {
                gcd_table[i][j] = gcd(i, j);
            }
        }

        vector<vector<int>> dp(max_val+1, vector<int>(max_val+1, 0));
        dp[0][0] = 1;

        for(int x : nums)
        {
            vector<vector<int>> next_dp(max_val + 1, vector<int>(max_val + 1, 0));
            
            for (int g1 = 0; g1 <= max_val; ++g1)
            {
                for (int g2 = 0; g2 <= max_val; ++g2)
                {
                    if (dp[g1][g2] == 0) continue;
                    
                    int ways = dp[g1][g2];

                    next_dp[g1][g2] = (next_dp[g1][g2] + ways) % MOD;

                    int next_g1 = gcd_table[g1][x];
                    next_dp[next_g1][g2] = (next_dp[next_g1][g2] + ways) % MOD;

                    int next_g2 = gcd_table[g2][x];
                    next_dp[g1][next_g2] = (next_dp[g1][next_g2] + ways) % MOD;
                }
            }

            dp = next_dp;
        }

        int total_valid_pairs = 0;
        for(int i=1 ; i <= max_val ; ++i)
        {
            total_valid_pairs = (total_valid_pairs + dp[i][i]) % MOD;
        }

        return total_valid_pairs;
    }
};