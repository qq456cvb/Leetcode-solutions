class Solution {
    vector<int> result;
    vector<int> count;
public:
    int findMax(vector<int>& nums) {
        int range = (int)nums.size() / 3;
        int i = 0, major = nums[0], cnt = 1;
        while (++i < nums.size()) {
            if (cnt == -range) {
                major = nums[i];
                cnt = 1;
            } else if (nums[i] == major) {
                cnt++;
            } else {
                cnt--;
            }
        }
        result.push_back(major);
        cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == major) {
                cnt++;
            }
        }
        count.push_back(cnt);
        if (cnt <= nums.size()/3) {
            result.pop_back();
        }
        return major;
    }
    
    int findSubMax(vector<int>& nums) {
        if (nums.size() == count[0]) {
            return -1;
        }
        int i = -1, major = nums[0], cnt = 0;
        while (++i < nums.size()) {
            if (nums[i] == result[0]) {
                continue;
            }
            if (cnt == 0) {
                major = nums[i];
                cnt = 1;
            } else if (nums[i] == major) {
                cnt++;
            } else {
                cnt--;
            }
        }
        result.push_back(major);
        cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == major) {
                cnt++;
            }
        }
        if (cnt <= nums.size()/3) {
            result.pop_back();
        }
        count.push_back(cnt);
        return major;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) {
            return result;
        }
        findMax(nums);
        findSubMax(nums);
        return result;
    }
};