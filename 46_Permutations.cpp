class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }
        int i = 0;
        for (i = nums.size()-1; i >= 0; i--) {
            if(nums[i] > nums[i-1]) {
                break;
            }
            if (i == 1) {
                break;
            }
        }
        int j = i - 1;
        while(nums[i] > nums[j] && i < nums.size()) {
            i++;
        }
        i--;
        swap(nums[i], nums[j]);
        if (i == j) {
            nums.clear();
        } else {
            reverse(nums.begin()+j+1, nums.end());
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if (nums.size() == 1) {
            result.push_back(nums);
            return result;
        }
        while (nums.size() > 0) {
            result.push_back(nums);
            nextPermutation(nums);
        }
        return result;
    }
};