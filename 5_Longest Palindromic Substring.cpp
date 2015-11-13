#define MIN(a,b) a>b?b:a
#define MAX(a,b) a>b?a:b
class Solution {
    string longestStr = "";
    int maxlen = 0;
    int len[2000] = {0};
public:
    string longestPalindrome(string s) {
        for (int i = 0; i < 2000; i++) {
            len[i] = 0;
        }
        string str = "#";
        for (int i = 0; i < s.length(); i++) {
            str += s[i];
            str += "#";
        }
        int id = 1, mx = 2;
        len[0] = 1;
        len[1] = 2;
        for (int i = 2; i < str.length(); i++) {
            if (mx > i) {
                len[i] = MIN(len[2*id-i], mx-i);
            } else {
                len[i] = 1;
            }
            while (str[i-len[i]+1] == str[i+len[i]-1] && i-len[i]+1>=0) {
                len[i]++;
            }
            len[i]--;
            if (len[i]+i-1 > mx) {
                mx = len[i]+i-1;
                id = i;
            }
        }
        int maxLen = 0, maxI = 0;
        for (int i = 1; i < str.length(); i++) {
            if (len[i] > maxLen) {
                maxLen = len[i];
                maxI = i;
            }
        }
        return s.substr((maxI-maxLen+1)/2, maxLen-1);
    }
    
};
