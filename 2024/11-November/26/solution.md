# Solution - 26 Nov 2024

---
## [2924. Find Champion II](https://leetcode.com/problems/find-champion-ii)

### cpp
```cpp
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        pair<int, int> cnt[n];

        for(auto &edge:edges) {
            cnt[edge[0]].second++;
            cnt[edge[1]].first++;
        }

        int ans = -1;
        for(int i=0; i<n; ++i) {
            if(cnt[i].first == 0) {
                if(ans == -1) ans = i;
                else return -1;
            }
        }

        return ans;
    }
};
```
