#include <iostream>
#include <stack>
using namespace std;

string f(string s) {
    int n = s.size();
    stack<string> st;

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            st.push(string(1, ch));
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string ans = string(1, ch) + t2 + t1;
            st.push(ans);
        }
    }
    return st.top();
}

int main() {
    string postfix = "ab+c*";
    cout << "Prefix: " << f(postfix) << endl;
    return 0;
}
