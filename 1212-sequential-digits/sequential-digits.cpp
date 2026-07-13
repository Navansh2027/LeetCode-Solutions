class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        
        vector<int> ans;

        for(int i=2 ; i <= 9 ; i++)
        {
            for(int j=0 ; j+i <= 9 ; j++)
            {
                int num = stoi(s.substr(j, i));

                if(num >= low && num <= high)
                
                ans.push_back(num);
            }
        }

        return ans;
    }
};