#include<iostream>
using namespace std;

class Stack {
    char stack[100];
    int top;
public:
    Stack() {
        top=-1;
    }

    void push(char x) {
        stack[++top]=x;
    }

    char pop() {
        return stack[top--];
    }

    bool isempty() {
        if(top==-1)
            return true;
        return false;
    }

    bool checkpref(char op1,char op2) {
        if((op1=='+' || op1=='-') && (op2=='+' || op2=='-'))
            return false;
        if((op1=='*' || op1=='/') && (op2=='*' || op2=='/'))
            return false;
        if((op1=='*' || op1=='/') && (op2=='+' || op2=='-'))
            return false;
        if((op1=='+' || op1=='-') && (op2=='*' || op2=='/'))
            return true;        
    }

    char sttop() {
        return stack[top];
    }

};

int main() {
    Stack s;
    string str="1+2-3*4/2";
    char res[100];
    int j=0;
    for(int i=str.length()-1;i>=0;i--) {
        if(str[i]=='+'|| str[i]=='-'|| str[i]=='/'|| str[i]=='*') {
            if(s.isempty())
                s.push(str[i]);
            else {
                if(!s.checkpref(s.sttop(),str[i])) {
                    res[j]=s.pop();
                    j++;
                    s.push(str[i]);
                }
                else 
                    s.push(str[i]);
            }
        }
        else {
            res[j]=str[i];
            j++;
        }
    }
    res[j]=s.pop();
    j++;
    for(int i=j-1;i>=0;i--)
        cout<<res[i];
    return 0;
}