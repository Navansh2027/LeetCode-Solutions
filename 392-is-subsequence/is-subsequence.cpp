class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = 0;
        int j = 0;
        while(n < s.length() && j < t.length())
        {
            if(s[n] == t[j])
            {
                n++;
            }
            j++;
        }
        return n == s.length();
    }
};