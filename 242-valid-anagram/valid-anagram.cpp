class Solution {
public:
    bool isAnagram(string s, string t) {
        int a = s.size();
        int b = t.size();

        if(a != b)
            return false;

        int count[26] = {0};

        for(int i=0 ; i<a ; i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int j=0 ; j<26 ; j++)
        {
            if(count[j] != 0) return false;
        }

        return true;
    }
};