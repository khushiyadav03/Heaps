class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int> ans;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i<n; i++){
            pq.push(arr[i]);
            
            // keep heap size <= k
            if(pq.size() > k){
                pq.pop();
            }
            
            // if less than k elements, kth largest doesn't exist
            if(pq.size() < k){
                ans.push_back(-1);
            }
            // heap size == k -> top is the kth largest element
            else {
                ans.push_back(pq.top());
            }
        }
        
        return ans;
    }
};