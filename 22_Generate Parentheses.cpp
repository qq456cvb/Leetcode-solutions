class Solution {
    vector<string> result;
public:
    void helper(string str, int half, int full, int n) {
        if (half + full < n) {
            if (half == 0) {
                helper(str+"(", half+1, full, n);
            } else {
                helper(str+"(", half+1, full, n);
                helper(str+")", half-1, full+1, n);
            }
        } else {
            if (full == n) {
                result.push_back(str);
            } else {
                helper(str+")", half-1, full+1, n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return this->result;
    }
};