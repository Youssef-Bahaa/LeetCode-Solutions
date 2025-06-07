class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int kk, vector<int>& nums) {
        k = kk;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (k < pq.size())
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (k < pq.size()) {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */