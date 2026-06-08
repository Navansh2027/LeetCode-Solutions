class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less_than;
        vector<int> equals_to;
        vector<int> greater_than;

        for(int num : nums)
        {
            if(num < pivot)
            {
                less_than.push_back(num);
            }
            else if(num == pivot)
            {
                equals_to.push_back(num);
            }
            else
            {
                greater_than.push_back(num);
            }
        }

        vector<int> result;

        result.insert(result.end(), less_than.begin(), less_than.end());
        result.insert(result.end(), equals_to.begin(), equals_to.end());
        result.insert(result.end(), greater_than.begin(), greater_than.end());

        return result;
    }
};