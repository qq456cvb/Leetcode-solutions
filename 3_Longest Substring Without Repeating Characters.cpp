class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int longest = 0;
        map<char, bool> mmap;
        while (j < s.length()) {
            if (mmap.find(s[j]) == mmap.end()) {
                while (j < s.length() && mmap.find(s[j]) == mmap.end()) {
                    mmap[s[j++]] = true;
                }
                if (j - i > longest) {
                    longest = j - i;
                }
            } else {
                if (mmap.find(s[i]) != mmap.end()) {
                    mmap.erase(mmap.find(s[i]));
                    i++;
                }
            }
        }
        return longest;
    }
};