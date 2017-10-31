class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        int res = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            int numVertical = 0, local = 0, duplicate = 0;
            unordered_map<long, int> map;
            for (int j = i + 1; j < points.size(); ++j) 
                if (points[i].x == points[j].x)
                    if (points[i].y == points[j].y) {
                        ++duplicate;
                    }
                    else {
                        ++numVertical;
                    }
                else {
                    long slopeKey = key((points[i].y - points[j].y), (points[i].x - points[j].x));
                    ++map[slopeKey];
                    local = max(local, map[slopeKey]);
                }
            local = max(local, numVertical);
            res = max(res, local + duplicate);
        }
        return res + 1;
    }
private:
    long key(int a, int b) {
        if (a == 0) return 0;
        if (a < 0) {
            a = -a;
            b = -b;
        }
        int c = gcd(a, b<0?-b:b);
        long res = a/c;
        res <<= 32;
        res += b/c;
        return res;
    }

    int gcd(int a, int b) {
        if(b == 0) return a;
        else return gcd(b, a%b);
    }
};