#define INT_MAX (1<<31)-1
#define INT_MIN -(1<<31)
class Solution {
public:
    int reverse(int x) {
        long long suffix = 1;
        long long result = 0;
        while (x / suffix) {
            result *= 10;
            result += (x % (suffix*10)) / suffix;
            if (!(result >= INT_MIN && result <= INT_MAX)) {
                return 0;
            }
            suffix *= 10;
        }
        return result;
    }
};