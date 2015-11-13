class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long now = 1;
        vector<int> results;
        results.push_back(1);
        for (int i = rowIndex; i > 0; i--) {
            now = now*i/(rowIndex-i+1);
            results.push_back(now);
        }
        return results;
    }
};