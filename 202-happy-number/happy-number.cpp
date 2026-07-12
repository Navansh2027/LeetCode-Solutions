class Solution {
public:

    int next_number(int n)
    {
        int sum = 0;

        while(n > 0)
        {
            int digit = n % 10;

            sum += digit * digit;

            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_set<int> visited;

        while(n != 1)
        {
            if(visited.count(n))
                return false;

            visited.insert(n);

            n = next_number(n);
        }

        return true;
    }
};