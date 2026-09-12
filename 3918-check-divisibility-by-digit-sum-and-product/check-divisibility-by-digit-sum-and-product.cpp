class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
       int original = n;
        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            mul *= digit;
            n /= 10;
        }
        
      return (original%(sum+mul))==0;
    }
};