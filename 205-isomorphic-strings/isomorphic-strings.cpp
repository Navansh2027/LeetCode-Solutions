class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i=0 ; i<s.size() ; i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            if (mp1.count(c1) == 0 && mp2.count(c2) == 0)
            {
                mp1[c1] = c2;
                mp2[c2] = c1;
            }
            else
            {
                if (mp1[c1] != c2 || mp2[c2] != c1)
                {
                    return false;
                }
            }
        }

        return true;
    }
};