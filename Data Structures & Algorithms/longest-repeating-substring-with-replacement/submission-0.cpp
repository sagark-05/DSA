class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int max_len = 0;
        int max_cnt = 0;
        int right = 0;
        vector<int> freq(26,0);

        while(right < s.size()){
            freq[s[right]- 'A']++;

            max_cnt = max(max_cnt , freq[s[right] - 'A']);

            while((right - left + 1) - max_cnt > k){
                freq[s[left]- 'A']--;
                left++;
            }

            max_len = max(max_len , right - left + 1);
            right++;
        }

        return max_len;
    }
};
