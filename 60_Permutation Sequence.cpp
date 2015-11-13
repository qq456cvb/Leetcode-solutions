class Solution {
    string result;
public:
    int factor(int i) {
        if (i == 1) {
            return i;
        }
        return i * factor(i-1);
    }
    
    string getPermutation(int n, int k) {
        string str = "1";
        int saven = n;
        if (n == 1) {
            return str;
        } else {
            str = "";
        }
        n = n-1;
        int fac = factor(n);
        while (n-- > 0) {
            int idx = (k-1)/fac+1;
            int i = 1, j = 1;
            while (j <= idx) {
                if (str.find((char)(i+48)) == string::npos) {
                    j++;
                }
                i++;
            }
            str += (char)(i-1+48);
            k -= fac * (idx-1);
            fac /= n+1;
        }
        for (int i = 1; i <= saven; i++) {
            if (str.find((char)(i+48))  == string::npos) {
                str += (char)(i+48);
                break;
            }
        }
        return str;
    }
};