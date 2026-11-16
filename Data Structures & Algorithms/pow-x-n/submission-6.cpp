class Solution {
public:
    double myPow(double x, int n) {
        double y = x;
      
        if (x == 1) {return 1;}
        if (x == -1) {
            int res = (n%2 == 0) ? 1 : -1;
            return res;
        }
            
        if (n >= INT_MAX || n <= INT_MIN) { 
            return 0.0;
        }
        if (n == 0) {
            return 1.0;
        } else  {
            for (int i = 1; i < abs(n); i++){
                x *= y;
            }
        }
        if (n < 0) {
            return (1/x);
        }
        
        
        return x;
    }
};
