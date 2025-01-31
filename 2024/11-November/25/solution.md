# Solution - 25 Nov 2024

---
## [773. Sliding Puzzle](https://leetcode.com/problems/sliding-puzzle)

### cpp
```cpp
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int ans = 0;
        string valid="123450", begin="";
        vector<int> moves[] = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};

        for(int i=0; i<2; ++i)
            for(int j=0; j<3; ++j)
                begin.push_back('0' + board[i][j]);

        unordered_set<string> visited;
        visited.insert(begin);
        queue<pair<string, int>> q;
        q.push({begin, 0});

        while(q.size()) {
            auto p = q.front(); q.pop();
            string cur = p.first;
            int dist = p.second, idx = cur.find("0");

            if(cur == valid) return dist;

            for(int &i:moves[idx]) {
                string next = cur;
                swap(next[idx], next[i]);

                if(!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, dist+1});
                }
            }
        }
        
        return -1;
    }
};
```
