#include <bits/stdc++.h>
using namespace std;
struct Stack{
    int Item[100];
    int Top;
};
struct Stack1{
    char Item[100];
    int Top;
};
Stack1 StrStack;
void Initialize1()
{
    StrStack.Top=-1;
}
bool IsEmpty1()
{
    if (StrStack.Top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
char StackTop1()
{
    return StrStack.Item[StrStack.Top];
}
void Push1(char x)
{
    if (StrStack.Top==99)
    {
        cout<<"Stack Overflow"<<"\n";
    }
    else
    {
        StrStack.Top++;
        StrStack.Item[StrStack.Top]=x;
    }
}
char Pop1()
{
    if (IsEmpty1())
    {
        cout<<"Stack Underflow"<<"\n";
    }
    else
    {
        int x=StrStack.Item[StrStack.Top];
        StrStack.Top--;
        return x;
    }
}
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
void RevExp(char *PrefixExp)
{
    Initialize1();
    int i=0,j=0;
    while(PrefixExp[i]!='\0')
    {
        Push1(PrefixExp[i]);
        i++;
    }
    while(!IsEmpty1())
    {
        PrefixExp[j]=Pop1();
        j++;
    }
    cout<<PrefixExp;
}
int prefixeval(char *PrefixExp)
{
    RevExp(PrefixExp);
    int i=0;
    while(PrefixExp[i]!='\0')
    {
        if(PrefixExp[i]==' ' || PrefixExp=="\t")
        {
            continue;
        }
        else if(isdigit(PrefixExp[i]))
        {
            Push(PrefixExp[i]-'0');
        }
        else{
            int a=Pop();
            int b=Pop();
            int val;
            switch(PrefixExp[i])
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
    char PrefixExp[100];
    cin>>PrefixExp;
    int result=prefixeval(PrefixExp);
    cout<<"\n"<<result;
    return 0;
}