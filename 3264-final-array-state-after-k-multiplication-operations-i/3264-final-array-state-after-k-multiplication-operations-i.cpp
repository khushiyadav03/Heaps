class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // min heap: (value, index)
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        int n = nums.size();

        // initial heap
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        // perform k operations
        while (k--) {
            auto [val, idx] = pq.top();
            pq.pop();

            val = val * multiplier;
            nums[idx] = val;

            pq.push({val, idx});
        }

        return nums;
    }
};
