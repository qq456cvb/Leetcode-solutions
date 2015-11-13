class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> mmap;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            mmap[target - nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            iter = mmap.find(nums[i]);
            if (iter != mmap.end()) {
                if (iter->second != i) {
                    ans.push_back(i+1);
                    ans.push_back(iter->second+1);
                    return ans;
                }
            }
        }
        return ans;
    }
};