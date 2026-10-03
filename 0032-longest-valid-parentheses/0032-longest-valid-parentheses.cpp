class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int max_len = 0;

        vector <int> stack;

        stack.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                stack.pop_back();
                if (stack.empty()) {
                    stack.push_back(i);
                } else {
                    max_len = max(max_len, i - stack.back());
                }
            }
        }
        return max_len;
    }
};