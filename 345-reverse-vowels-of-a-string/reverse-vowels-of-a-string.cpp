class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vowel_stack;
        
        for(char n : s)
        {
            if(isVowel(n))
            {
                vowel_stack.push(n);
            }   
        }

        for(int i=0 ; i<s.length() ; i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = vowel_stack.top();
                vowel_stack.pop();
            }
        }
        return s;
    }

    bool isVowel(char v)
    {
        v = tolower(v);
        return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
    }
};