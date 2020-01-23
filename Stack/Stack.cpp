#include<iostream>
#define SIZE 100
using namespace std;

class Stack {
    int top,stack[SIZE];
public:
    Stack() {
        top=-1;
    }

    void push(int a) {
        if(top==SIZE-1)
            cout<<"Stack is full\n";
        else
            stack[++top]=a;
    }

    void pop() {
        if(top==-1)
            cout<<"Stack is empty\n";
        else
            cout<<stack[top--]<<"\n";
    }

    void display() {
        for(int i=top;i>-1;i--)
            cout<<stack[i]<<"\n";
    }

};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.display();
    return 0;
}