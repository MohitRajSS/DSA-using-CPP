#include<iostream>
#include<vector>
using namespace std;

int maxSize=10;
int S1[10];
int S2[10];
int top1=-1;
int top2=-2;

void push(int data){
    if(top1==maxSize){
        cout<<"Sorry the queue is full"<<endl;
    }else{
        top1++;
        S1[top1]=data;
        cout<<data<<": Has been pushed"<<endl;
    }
}

void pop(){
    if(top1==-1){
        cout<<"The queue is empty"<<endl;
    }else{
        while(top1!=-1){
            top2++;
            S2[top2]=S1[top1];
            top1--;
        }
        cout<<S2[top2]<<"Has been popped"<<endl;
        top2--;
        while(top2!=-1){
            top1++;
            S1[top1]=S2[top2];
            top2--;
        }
    }
}

void peek(){
    if(top1==-1){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<S1[0]<<"Is the fucking topmost element of Queue"<<endl;
    }
}

void isEmpty(){
    if(top1==-1){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<"queue is not empty"<<endl;
    }
}

void printQueue(){
    if(top1==-1){
        cout<<"queue is empty"<<endl;
    }else{
    //Node*temp=head;
    cout<<"<--";
    for(int i=0;i<=top1;i++){
        cout<<S1[i];
        cout<<"--";
    }
    // while(temp!=NULL){
    //     cout<<temp->data;
        
    //     temp=temp->next;
    // }
    cout<<"<--";
    }
}

int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    cout<<endl;
    cout<<endl;

    printQueue();
    //Psize();
    peek();
    isEmpty();

    cout<<endl;
    cout<<endl;

    pop();
    pop();
    pop();

    printQueue();
   // Psize();
    peek();
    isEmpty();

    cout<<endl;
    cout<<endl;

    return 0;
}