class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // count freq
        for (int n : nums) {
            freq[n]++;
        }

        // min heap (freq, n)
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        // keep heap size = k
        for (auto &it : freq) {
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // extract result
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans; // O(n log n)
    }
};
