class Solution {
    vector<vector<int>> result;
public:
    void helper(const vector<int>& nums, int combine) {
        if (combine & (1<<nums.size())) {
            return;
        }
        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            if (combine & (1<<i)) {
                tmp.push_back(nums[i]);
            }
        }
        result.push_back(tmp);
        helper(nums, combine+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return result;
    }
};