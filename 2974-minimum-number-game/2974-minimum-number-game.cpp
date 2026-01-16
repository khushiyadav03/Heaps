class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        // push all elements into min heap
        for(int x : nums){
            pq.push(x);
        }

        vector<int> arr;

        while(!pq.empty()){
            int alice = pq.top();
            pq.pop();

            int bob = pq.top();
            pq.pop();

            arr.push_back(bob);
            arr.push_back(alice);
        }

        return arr;
    }
};