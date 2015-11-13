class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        unsigned long x1 = x - 1;
        unsigned s = 1;
        unsigned g0,g1;
    
        /* initial value */
        if (x1 > 65535) {s += 8; x1 >>= 16;}
        if (x1 > 255)   {s += 4; x1 >>= 8;}
        if (x1 > 15)    {s += 2; x1 >>= 4;}
        if (x1 > 3)     {s += 1; x1 >>= 2;}
    
        /* iterate */
        g0 = 1 << s;
        g1 = (g0 + (x >> s)) >> 1;
        while(g1 < g0)
        {
           g0 = g1;
           g1 = (g0 + x/g0) >> 1;
        }
        return g0;
    }
};