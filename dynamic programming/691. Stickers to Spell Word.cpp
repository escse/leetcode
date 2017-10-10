struct State {
    State() { 
        res = 0;
        memset(c, 0, sizeof(c));
    }
    State(const string& s): State() {
        for (auto &e: s) {
            c[e-'a'] += 1;
        }
        cnt = count_if(c, c+26, [](int x){return x!= 0;});
    }
    int cnt, res, c[26];
    void operator-=(const map<char, int>& m) {
        for (auto &e: m) {
            if (c[e.first - 'a'] != 0 && c[e.first - 'a'] <= e.second) --cnt;
            c[e.first - 'a'] = max(c[e.first - 'a'] - e.second, 0);
        }
    }
};

class Solution {
public:
    bool contain(map<char, int>& l, map<char, int>& r) {
        for (auto &e: l) {
            if (r.find(e.first) == r.end() || r[e.first] < e.second) return false;
        }
        return true;
    }

    int minStickers(vector<string>& stickers, string target) {
        string s, t(target);
        for (auto &e: stickers) s += e;
        sort(s.begin(), s.end()); sort(t.begin(), t.end());
        if (!includes(s.begin(), s.end(), t.begin(), unique(t.begin(), t.end()))) return -1;
        vector<map<char, int>> v(stickers.size());
        for (int i = 0; i < stickers.size(); ++i) {
            for (auto &e: stickers[i]) {
                if (target.find(e) != -1)
                    v[i][e] += 1;
            }
        } 
        for (int i = 0; i < v.size();) {
            int flag = 1;
            for (int j = 0; j < v.size(); ++j) {
                if (i == j || v[j].empty()) continue;
                if (contain(v[i], v[j])) {
                    v.erase(v.begin()+i);
                    flag = 0;
                    break;
                }
            }
            if (flag) ++i;
        }

        State start(target);
        queue<State> q;
        q.push(start);
        
        while (true) {
            for (auto &e: v) {
                auto c = q.front();
                c -=  e;
                c.res += 1;
                if (c.cnt == 0) return c.res;
                q.push(c);
            }
            q.pop();
        }
    }
};
