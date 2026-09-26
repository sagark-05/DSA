class Solution {
public:
    string capitalizeTitle(string title) {
        //convert string into lower case
        for (char &c : title){
            c = tolower(c);
        }

        // process each word
        int start = 0;
        for(int i=0; i<= title.length() ; i++){
            if(i == title.length() || title[i] == ' '){
                if(i - start > 2){
                    title[start] = toupper(title[start]);
                }

                start  = i + 1;
            }
        }

        return title;
    }
};