class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int un = (unsigned int) n;
         int res = 0;
         while (un) {
             res += un&1;
             un >>= 1;
         }
         return res;
     }
};