// 矩阵快速幂运算

struct mat2x2 {
    long a11, a12, a21, a22;
    mat2x2(long a, long b, long c, long d): a11(a), a12(b), a21(c), a22(d){}
    // mat2x2(const mat2x2& rhs): a11() {}
    mat2x2 operator*(mat2x2 &rhs) {
        long a = a11 * rhs.a11 + a12 * rhs.a21;
        long b = a11 * rhs.a12 + a12 * rhs.a22;
        long c = a21 * rhs.a11 + a22 * rhs.a21;
        long d = a21 * rhs.a12 + a22 * rhs.a22;
        return mat2x2(a, b, c, d);
    }
  
    mat2x2 operator^(int c) {
        mat2x2 a(*this);
        mat2x2 res(1,0,0,1);
        while (c != 0) {
            if (c & 1) {
                res = res * a;
            }
            c >>= 1;
            a = a* a;
        }
        return res;
    }
};


class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 0) return 0;
        if (n <= 2) return 1;
        mat2x2 m(1,1,1,0);
        m = m^(n-2);
        return m.a11 + m.a12;
    }
};