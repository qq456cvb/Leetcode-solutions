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
            reverse(nums.begin()+j, nums.end());
        } else {
            reverse(nums.begin()+j+1, nums.end());
        }
    }
};