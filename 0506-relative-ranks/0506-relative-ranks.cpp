class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);

        // max heap: (score, index)
        priority_queue<pair<int,int>> p;

        for (int i = 0; i < n; i++) {
            p.push({score[i], i});
        }

        int rank = 1;
        while (!p.empty()) {
            auto top = p.top();
            p.pop();

            int idx = top.second;

            if (rank == 1)
                ans[idx] = "Gold Medal";
            else if (rank == 2)
                ans[idx] = "Silver Medal";
            else if (rank == 3)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(rank);

            rank++;
        }

        return ans;
    }
};
