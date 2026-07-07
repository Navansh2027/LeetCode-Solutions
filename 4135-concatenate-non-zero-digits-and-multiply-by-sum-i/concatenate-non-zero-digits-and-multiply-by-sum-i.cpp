class Solution {
public:
    long long sumAndMultiply(int n) {

        string in = to_string(n);
        long long x = 0;
        int sum = 0;

        for(char i : in)
        {

            int curr = i - '0';

            if(curr == 0)
            {
                continue;  
            }

            x = x * 10 + curr;
            sum += curr;
        }
        
        return x * sum;
    }
};