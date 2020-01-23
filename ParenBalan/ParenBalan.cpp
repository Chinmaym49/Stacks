#include<iostream>
using namespace std;

class Stack {
    char stack[100];
    int top;
public:
    Stack() {
        top=-1;
    }

    void pop() {
        top--;
    }

    void push() {
        stack[++top]='(';
    }

    bool isempty() {
        if(top==-1)
            return true;
        return false;
    }

};

int main() {
    Stack *s=new Stack();
    string str="(())()";
    for(int i=0;str[i]!='\0';i++) {
        if(str[i]==')') {
            if(s->isempty()) {
                cout<<"U\n";
                return 0;
            }
            s->pop();
        }
        else {
            s->push();
        }
    }
    if(!s->isempty())
        cout<<"U\n";
    else
        cout<<"B\n";
    return 0;
}