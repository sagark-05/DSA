class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> ans;
        for (int x : nums) {
            ans.push_back(1LL * x * x);
        }

        sort(ans.begin(), ans.end());
        int mid = nums.size() / 2;
        long long res = 0;
        for (int i = mid;i <  ans.size(); i++) {
            res += ans[i];
        }
        for (int i = 0; i < mid; i++) {
            res -= ans[i];
        }

        return res;
    }
};