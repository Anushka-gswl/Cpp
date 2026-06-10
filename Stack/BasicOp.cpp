#include <bits/stdc++.h>
using namespace std;
struct Stack{
    int Item[10];
    int Top;
};
Stack S;
void Initialize()
{
    S.Top=-1;
}
bool IsEmpty()
{
    if (S.Top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int StackTop()
{
    return S.Item[S.Top];
}
void Push(int x)
{
    if (S.Top==9)
    {
        cout<<"Stack Overflow"<<"\n";
    }
    else
    {
        S.Top++;
        S.Item[S.Top]=x;
    }
}
int Pop()
{
    if (IsEmpty())
    {
        cout<<"Stack Underflow"<<"\n";
    }
    else
    {
        int x=S.Item[S.Top];
        S.Top--;
        return x;
    }
}
int main() {
    Initialize();
    Push(100);
    Push(200);
    Push(300);
    Push(400);
    Push(500);
    Pop();
    Pop();
    Pop();
    cout<<IsEmpty()<<"\n";
    cout<<StackTop();
    return 0;
}