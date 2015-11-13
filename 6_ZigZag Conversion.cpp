class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string str = "";
        int step = (numRows-1)*2;
        for (int i = 1; i <= numRows; i++) {
            int offset = i-1;
            //ith line
            if (i == 1 || i == numRows) {
                while(offset < s.length()) {
                    str += s[offset];
                    offset += step;
                }
            } else {
                bool odd = true;
                int substep = step-(i-1)*2;
                while(offset < s.length()) {
                    str += s[offset];
                    offset += odd?substep:(step-substep);
                    odd = !odd;
                }
            }
        }
        return str;
    }
};