typedef vector<int> vi;
const int inf = 0x7fffffff, ninf = 0x80000000;
class Solution {
    int kth_min(vi& a, vi& b, int k, int n, int m){
        #define A(i) (i < 1 ? ninf : (i > n ? inf : a[i - 1]))
        #define B(i) (i < 1 ? ninf : (i > m ? inf : b[i - 1]))
        int l = 0, r = n + 1, x;
        while(l <= r){
            x = (l + r) >> 1;
            if(A(x) > B(k - x + 1)) r = x - 1;
            else if(B(k - x) > A(x + 1)) l = x + 1;
            else return max(A(x), B(k - x));
        }
        return 0;   //never execute , just to hide the warning :)
        #undef A
        #undef B
    }
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(n > m) return findMedianSortedArrays(b, a); //make sure that a.size() <= b.size()
        if((m + n) & 1) return kth_min(a, b, (m + n + 1) >> 1, n, m);
        return (0.0 + kth_min(a, b, (m + n + 1) >> 1, n, m) + kth_min(a, b, ((m + n) >> 1) + 1, n, m)) * 0.5;
    }
};