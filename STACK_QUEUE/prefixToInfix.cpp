#include<iostream>
#include<vector>
#include<stack>
using namespace std;

string f(string s){
    int n=s.size();
    stack<string>st;

    for(int i=n-1;i>=0;i--){
        char ch=s[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            st.push(string(1,ch));
        }else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string result='('+t1+string(1,ch)+t2+')';
            st.push(result);
        }
    }
    return st.top();
}
int main(){
    string prefix = "*+a-bc+/de*fg-+hi*j-kl+mn*+op-qr+/st-uv+*wx/yz+*a-bc+/de*fg-+hi*j-kl+mn*+op-qr";
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << f(prefix) << endl;
    return 0;
}