#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int>q;

void Push(int data){
    int s=q.size();
    q.push(data);
    for(int i=0;i<s;i++){
        q.push(q.front());
        q.pop();
    }
    cout<<data<<" has been pushed"<<endl;
}

void Pop(){
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }
    int n=q.front();
    cout<<n<<" has been popped"<<endl;
    q.pop();
}

int main(){
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Push(5);

    Pop();
    Pop();
    Pop();
    return 0;
}