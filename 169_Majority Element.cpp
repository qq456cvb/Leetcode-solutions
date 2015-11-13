class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = -1, major = nums[0], cnt = 0;
        while (++i < nums.size()) {
            if (cnt == 0) {
                major = nums[i];
                cnt = 1;
            } else if (nums[i] == major) {
                cnt++;
            } else {
                cnt--;
            }
        }
        cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == major) {
                cnt++;
            }
        }
        if (cnt > nums.size()/2) {
            return major;
        }
        return -1;
    }
};