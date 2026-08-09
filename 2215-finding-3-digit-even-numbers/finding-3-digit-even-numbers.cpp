class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        vector<int> ans;

        for (int i = 0; i < digits.size(); i++) {

            // First digit cannot be 0
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < digits.size(); j++) {

                // Cannot use the same digit twice
                if (j == i)
                    continue;

                for (int k = 0; k < digits.size(); k++) {

                    // Cannot use the same digit twice
                    if (k == i || k == j)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100 +
                              digits[j] * 10 +
                              digits[k];

                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());

        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};