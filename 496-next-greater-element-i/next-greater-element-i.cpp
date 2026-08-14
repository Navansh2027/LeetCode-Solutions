class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> next_greater;

        for(int num : nums2)
        {
            while(!st.empty() && st.top() < num)
            {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> ans;
        for(int num : nums1)
        {
            if(next_greater.count(num))
            {
                ans.push_back(next_greater[num]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};