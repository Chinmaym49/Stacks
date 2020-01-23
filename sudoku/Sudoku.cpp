#include<iostream>
#include<fstream>
using namespace std;

class Stack {
    int stack[100][2],top;
public:
    Stack() {
        top=-1;
    }

    void push(int x,int y) {
        top++;
        stack[top][0]=x;
        stack[top][1]=y;
    }

    void pop(int*arr) {
        arr[0]=stack[top][0];
        arr[1]=stack[top][1];
        top--;
    }

    bool isEmpty() {
        if(top==-1)
            return true;
        return false;
    }

};

bool checkRow(int arr[][10],int r,int c,int x) {
    for(int i=0;i<9;i++)
        if(arr[r][i]==x)
            return false;
    return true;
}

bool checkCol(int arr[][10],int r,int c,int x) {
    for(int i=0;i<9;i++)
        if(arr[i][c]==x)
            return false;
    return true;
}

bool checkNonet(int arr[][10],int r,int c,int x) {
    int m=int(r/3),n=int(c/3);
    for(int i=m*3;i<m*3+3;i++)
        for(int j=n*3;j<n*3+3;j++)
            if(i!=r && j!=c && arr[i][j]==x)
                return false;
    return true;
}

void loadGrid(int arr[][10]) {
    fstream f("prob.txt");
    int c;
    cout<<"Enter a no. between 1 and 20...";
    cin>>c;
    string line;
    while(f) {
        c--;
        getline(f,line);
        if(c==0)
            break;
    }
    int k=0;
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            if(line[k]=='.')
                line[k]='0';
            arr[i][j]=int(line[k]-'0');
            k++;
        }
    }
    f.close();
}

int main() {
    Stack s;
    int grid[10][10];
    loadGrid(grid);
    int arr[2];
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
    int r=0,c=0,x;
    while(true) {
        if(grid[r][c]==0) {
            x=1;
            while(!(checkRow(grid,r,c,x) && checkCol(grid,r,c,x) && checkNonet(grid,r,c,x))) {
                x++;
                if(x==10) {
                    grid[r][c]=0;
                    s.pop(arr);
                    r=arr[0];
                    c=arr[1];
                    x=grid[r][c];
                }
            }
            grid[r][c]=x;
            s.push(r,c);
        }
        c++;
        if(c==9) {
            r++;
            c=0;
            if(r==9)
                break;
        }
    }

    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}