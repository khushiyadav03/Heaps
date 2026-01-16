class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < N; i++) {
            pq.push(A[i]);
        }

        // Step 1: remove first K1 smallest elements
        for (int i = 0; i < K1; i++) {
            pq.pop();
        }

        long long sum = 0;

        // Step 2: sum elements strictly between K1 and K2
        for (int i = 0; i < K2 - K1 - 1; i++) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
