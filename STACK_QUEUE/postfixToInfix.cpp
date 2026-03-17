#include<iostream>
#include<stack>
using namespace std;

string f(string s){
    stack<string> st;
    int n = s.size();

    for(int i = 0; i < n; i++){
        char ch = s[i];

        if((ch >= 'a' && ch <= 'z') || 
           (ch >= 'A' && ch <= 'Z') || 
           (ch >= '0' && ch <= '9')) {
            st.push(string(1, ch));  // convert char to string
        } else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string result = "(" + t2 + string(1, ch) + t1 + ")";
            st.push(result);
        }
    }

    return st.top();
}

int main(){
    string postfix = "ab+cde+**fgh+*+ij-k+lm+n-opq*-+rs+tuv*+wxy*+z+/*ab+cde+**fgh+*+ij-k+lm+n-opq*-+rs+tuv*+wxy*+z+/*ab+cde+**fgh+*+ij-k+lm+n-opq*-+rs+tuv*+wxy*+z+/*";
    cout << "Postfix expression: " << postfix << endl;
    cout << "Infix expression: " << f(postfix) << endl;
    return 0;
}
