class Solution {
public:
    int numTrees(int n) {
        //by using catalen formula
        long long ans = 1;
        for(int i= 1; i<=n;i++){
            ans = ans * (2LL * (2 * i - 1)) / (i + 1) ;
        }

        return ans;
    }
};