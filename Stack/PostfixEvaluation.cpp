#include <bits/stdc++.h>
using namespace std;
struct Stack{
    int Item[100];
    int Top;
};
Stack OpndStack;
void Initialize()
{
    OpndStack.Top=-1;
}
bool IsEmpty()
{
    if (OpndStack.Top==-1)
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
    return OpndStack.Item[OpndStack.Top];
}
void Push(int x)
{
    if (OpndStack.Top==99)
    {
        cout<<"Stack Overflow"<<"\n";
    }
    else
    {
        OpndStack.Top++;
        OpndStack.Item[OpndStack.Top]=x;
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
        int x=OpndStack.Item[OpndStack.Top];
        OpndStack.Top--;
        return x;
    }
}
int postfixeval(char *PostfixExp)
{
    int i=0;
    while(PostfixExp[i]!='\0')
    {
        if(PostfixExp[i]==' ' || PostfixExp=="\t")
        {
            continue;
        }
        else if(isdigit(PostfixExp[i]))
        {
            Push(PostfixExp[i]-'0');
        }
        else{
            int b=Pop();
            int a=Pop();
            int val;
            switch(PostfixExp[i])
            {
                case '+': 
                {
                    val=a+b;
                    Push(val);
                    break;
                }
                case '-': 
                {
                    val=a-b;
                    Push(val);
                    break;
                }
                case '*': 
                {
                    val=a*b;
                    Push(val);
                    break;
                }
                case '/': 
                {
                    val=a/b;
                    Push(val);
                    break;
                }
                case '^': 
                {
                    val=pow(a,b);
                    Push(val);
                    break;
                }
                case '%': 
                {
                    val=a%b;
                    Push(val);
                    break;
                }
                default:
                {
                    cout<<"\nWrong Operator";
                    return -1;
                }
            }
        }
        i++;
    }
    return Pop();
}
int main() {
    Initialize();
    char PostfixExp[20];
    cin>>PostfixExp;
    int result=postfixeval(PostfixExp);
    cout<<"\n"<<result;
    return 0;
}