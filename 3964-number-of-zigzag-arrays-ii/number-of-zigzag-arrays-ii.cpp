class Solution {
public:
    static constexpr int MOD = 1000000007;

    using matrix = vector<vector<long long>>;

    matrix multi(const matrix& a, const matrix& b)
    {
        int n = a.size();

        matrix c(n, vector<long long>(n, 0));

        for(int i=0 ; i<n ; i++)
        {
            for(int k=0 ; k<n ; k++)
            {
                if(a[i][k] == 0) continue;

                for(int j=0 ; j<n ; j++)
                {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }

    matrix power(matrix base, long long exp)
    {
        int n = base.size();

        matrix result(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            result[i][i] = 1;

        while (exp) {

            if (exp & 1)
                result = multi(result, base);

            base = multi(base, base);
            exp >>= 1;
        }
        return result;    
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if(n == 1)
            return m;

        int states = 2 * m;

        matrix t(states, vector<long long>(states, 0));

        auto up = [&](int x)
        {
            return x;
        };

        auto down = [&](int x)
        {
            return x+m;
        };    

        for(int x=0 ; x<m ; x++)
        {
            for(int y=0 ; y<x ; y++)
            {
                t[up(x)][down(y)] = 1;
            }

            for(int y=x+1 ; y<m ; y++)
            {
                t[down(x)][up(y)] = 1;
            }
        }

        matrix p = power(t, n-1);

        vector<long long> start(states, 1);

        long long ans = 0;

        for(int j=0 ; j<states ; j++)
        {
            long long ways = 0;

            for (int i = 0; i < states; i++) {
                ways = (ways + start[i] * p[i][j]) % MOD;
            }
            ans = (ans + ways) % MOD;
        }
        return (int)ans;
    }
};