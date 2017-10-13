class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        istringstream in(s);
        string ss;
        while(getline(in, ss, ' ')) {
            if (!ss.empty())
                ++res;
        }
        return res;
    }
};

// python
// return len(s.split())