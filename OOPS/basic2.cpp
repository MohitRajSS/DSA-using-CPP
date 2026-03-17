#include<iostream>
#include<string>
using namespace std;

class binary{

    string s;

    public:
        void read(void);
        void check_binary(void);
        void display(void);
        void ones_compliment(void);
};

void binary::read(void){
    cout<<"Enter a binary NO ::";
    cin>>s;
    cout<<endl;
}

void binary::ones_compliment(void){
    check_binary();
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            s[i]='1';
            continue;
        }else if(s[i]=='1'){
            s[i]='0';
        }
    }
}

void binary::check_binary(void){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]!='0' && s[i]!='1'){
            cout<<"The number is not binary";
            cout<<endl;
            exit(0);
        }
    }
    cout<<"The number is binary"<<endl;
}

void binary::display(void){
    int n=s.size();
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    cout<<endl;
}



int main(){
    binary b;
    b.read();
    // b.check_binary();
    b.display();
    b.ones_compliment();
    b.display();

    // for(int i=0;i<s.length();i++){
    //     cout<<s[i]<<endl;
    // }
    return 0;
}