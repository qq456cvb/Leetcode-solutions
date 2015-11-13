class Solution {
public:
    unsigned long long climbStairs(int n) {
        int result[2] = {0,1};  
        if(n < 2)  
            return result[n];  
        long long fibOne = 1;  
        long long fibTwo = 1;  
        long long fibN   = 0;  
        int i = 0;  
        for(i = 2; i <= n; i++)  
        {  
            fibN = fibOne + fibTwo;  
              
            fibOne = fibTwo;  
            fibTwo = fibN;  
        }  
          
        return fibN;  
    }
};