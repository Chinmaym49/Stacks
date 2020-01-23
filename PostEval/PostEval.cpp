#include<iostream>
using namespace std;

class Stack {
    int top;
    int stack[100];
public:
    Stack() {
        top=-1;
    }

    void push(int x) {
        stack[++top]=x;
    }

    int pop() {
        return stack[top--];
    }

};

int main() {
    Stack *s=new Stack();
    string str="653+9*+";
    for(int i=0;str[i]!='\0';i++) {
        char x=str[i];
        if(str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
            s->push(str[i]-'0');
        else {
            int op2=s->pop();
            int op1=s->pop();
            if(str[i]=='+')
                s->push(op1+op2);
            else if(str[i]=='/')
                s->push(op1/op2);
            else if(str[i]=='-')
                s->push(op1-op2);
            else if(str[i]=='*')
                s->push(op1*op2);
        }
    }
    cout<<s->pop();
    return 0;
}