#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int prec(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

void rev(string *s){
    int n = s->size();
    for(int i = 0; i < n / 2; i++){
        swap((*s)[i], (*s)[n - i - 1]);
    }
}

void correction(string *s){
    int n = s->size();
    for(int i = 0; i < n; i++){
        if((*s)[i] == '(') (*s)[i] = ')';
        else if((*s)[i] == ')') (*s)[i] = '(';
    }
}

void f(string s){
    int n = s.size();
    stack<char> st;
    string ans = "";

    rev(&s);
    correction(&s);

    for(int i = 0; i < n; i++){
        char c = s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            ans += c;
        } else if(c == '('){
            st.push(c);
        } else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        } else {
            while(!st.empty() && prec(st.top()) > prec(c)){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    rev(&ans);
    cout << "Prefix expression: " << ans << endl;
}

int main() {
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    f(exp);
    return 0;
}
