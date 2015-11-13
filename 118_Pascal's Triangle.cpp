class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        if (numRows == 0) {
            return results;
        }
        vector<int> last = {1};
        results.push_back(last);
        for (int i = 2; i <= numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < i-1; j++) {
                tmp.push_back(last[j-1]+last[j]);
            }
            tmp.push_back(1);
            results.push_back(tmp);
            last = tmp;
        }
        return results;
    }
};