class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        if (envelopes.empty()) return 0;
        int size = envelopes.size();
        int dp[size];
        using t = pair<int, int>;
        for_each(dp, dp+size, [](int &e){e =1;});
        sort(envelopes.begin(), envelopes.end(), [](const t& l, const t& r){return l.first < r.first || l.first == r.first && l.second < r.second;});
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp, dp+size);
    }
};


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        if (envelopes.empty()) return 0;
        int size = envelopes.size();
        int dp[size];
        using t = pair<int, int>;
        sort(envelopes.begin(), envelopes.end(), [](const t& l, const t& r){return l.first < r.first || l.first == r.first && l.second > r.second;});
        int imax = std::numeric_limits<int>::max();
        fill(dp, dp+size, imax);
        for (int i = 1; i < size; ++i) {
            *lower_bound(dp, dp+size, envelopes[i].second) = envelopes[i].second;
        }
        return lower_bound(dp, dp+size, imax) - dp;
    }
};





