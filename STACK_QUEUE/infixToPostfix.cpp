#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }else if(c=='/' || c=='*'){
        return 2;
    }else if(c=='+' || c=='-'){
        return 1;
    }else{
        return -1;
    }
}

void f(string s){
    stack<char>st;
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++){
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            ans=ans+c;
        }else if(c=='('){
            st.push('(');
        }else if(c==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && prec(st.top())>=prec(c)){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<"postfix Expression: "<<ans<<endl;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  f(exp);
  return 0;
}