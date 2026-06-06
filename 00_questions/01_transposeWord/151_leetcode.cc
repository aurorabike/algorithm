Give a string, transpose it by word.
e.g. "I love C++"

out: "C++ love I"

leetcode https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75


class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if(!word.empty()) {
                    st.push(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if(!word.empty()) {
            st.push(word);
        }
        string ans;
        bool first = true;
        while(!st.empty()) {
            if(!first) {
                ans += ' ';
            }
            ans += st.top();
            st.pop();
            first = false;
        }
        return ans;
    }
};

class Solution {
    public:
        string reverseWords(string s) {
            int i = s.length() - 1;
            string ans;
            while(i >= 0) {
                int n = 0;
                while(i >=0 && s[i] == ' ') --i;
                while(i >=0 && s[i] != ' ') {
                    --i;
                    ++n;
                }
    
                if(n) {
                    ans += s.substr(i+1, n) + " ";
                }
            }
            return ans.substr(0, ans.size() - 1);
        }
    };
