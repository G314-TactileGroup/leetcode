class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        bool d[128][128]{};
        for (auto& e : mappings) {
            d[e[0]][e[1]] = true;
        }
        int m = s.size(), n = sub.size();
        for (int i = 0; i < m - n + 1; ++i) {
            bool ok = true;
            for (int j = 0; j < n && ok; ++j) {
                char a = s[i + j], b = sub[j];
                if (a != b && !d[b][a]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
};