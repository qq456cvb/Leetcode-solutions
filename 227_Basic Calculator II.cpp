class Solution {
    int result;
    int pos = 0;
    string str;
public:
    char getBit() {
        if (pos >= str.length()) {
            return 's';
        }
        return str[pos++];
    }
    
    int getTerm() {
        int a = getPrime();
        while (1) {
            char calc = getBit();
            if (calc != '*' && calc != '/') {
                pos--;
                return a;
            }
            if (calc == '*') {
                a *= getPrime();
            }
            if (calc == '/') {
                a /= getPrime();
            }
        }
        return -1;
    }
    
    int getPrime() {
        string num;
        while (1) {
            char digit = getBit();
            if (digit == ' ') {
                continue;
            } else {
                if (isdigit(digit)) {
                    num += digit;
                } else {
                    pos--;
                    stringstream ss;
                    ss << num;
                    int i;
                    ss >> i;
                    return i;
                }
            }
        }
    }
    
    int calculate(string s) {
        str = s;
        int a = getTerm();
        while (1) {
            char calc = getBit();
            if (calc != '+' && calc != '-') {
                return a;
            }
            if (calc == '+') {
                a += getTerm();
            }
            if (calc == '-') {
                a -= getTerm();
            }
        }

    }
    
};