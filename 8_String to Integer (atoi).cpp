#define INT_MAX (1<<31)-1
#define INT_MIN -(1<<31)
class Solution {
public:
    string convertPure(string str) {
        string result = "";
        int len = str.length();
        for (int i = 0; i < len; i++) {
            if (isdigit(str[i])) {
                result += str[i];
            } else {
                return result;
            }
        }
        return result;
    }
    string convert(string str) {
        string result = "";
        int len = str.length();
        for (int i = 0; i < len; i++) {
            if (str[i] == ' ') {
                continue;
            }
            if (str[i] == '+' || str[i] == '-') {
                return str[i]+convertPure(str.substr(i+1, len-i));
            }
            if (isdigit(str[i])) {
                return convertPure(str.substr(i, len-i));
            }
            return "";
        }
        return result;
    }
    int myAtoi(string str) {
        str = convert(str);
        long long result = 0;
        int len = str.length();
        bool neg = false;
        if (len > 0) {
            if (str[0] == '-') {
                neg = true;
            }
        }
        for (int i = len-1; i >= 0; i--) {
            if (len-i > 16) {
                break;
            }
            if (str[i] == '+' || str[i] == '-') {
                break;
            }
            result += (str[i]-48)*pow(10, (len-i-1));
        }
        if (neg) {
            result = -result;
        }
        if (result > INT_MAX) {
            return INT_MAX;
        }
        if (result < INT_MIN) {
            return INT_MIN;
        }
        return result;
    }
};