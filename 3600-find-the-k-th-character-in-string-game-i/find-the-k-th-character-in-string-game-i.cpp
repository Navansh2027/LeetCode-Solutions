class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.size() < k)
        {
            string temp = "";

            for (char c : s) 
                temp += char(c + 1);
            
            s += temp;
        }

        return s[k-1];    
    }
};