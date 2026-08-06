class Solution {
public:
    int digitProduct(int num) {
        int product = 1;

        while(num > 0)
        {
            product *= (num % 10);
            num /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int j)
    {
        while(true)
        {
            if (digitProduct(n) % j == 0)
                return n;

            n++;    
        }

        return -1;
    }
};