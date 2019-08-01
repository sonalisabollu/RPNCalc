//bollu
#include<iostream>
#include<string>
using namespace std;
struct StackNode
{
    int data;
    StackNode* next;
};
class MyStack
{
    StackNode* top;
    int size;
public:
    MyStack()
    {
        top=nullptr;
        size=0;
    }
    void push(int data)
    {
        StackNode* newNode=new StackNode();
        newNode->data=data;
        newNode->next=nullptr;
        if(top==nullptr)
        {
            top=newNode;
            size++;
            return;
        }
        newNode->next=top;
        top=newNode;
        size++;
    }
    int pop()
    {
        int data;
        if(top!=nullptr)
        {
            data=top->data;
            top=top->next;
            size--;
            return data;
        }
        return -1;
    }
    string toString()
    {
        string stackData="[";
        
        StackNode* temp=top;
        if(temp!=nullptr)
        {
            stackData+=to_string(temp->data);
            temp=temp->next;
        }
        while(temp!=nullptr)
        {
            
            stackData+=","+to_string(temp->data);
            temp=temp->next;
        }
        stackData+="]";
        return stackData;
    }
    int Size()
    {
        return size;
    }
    void clear()
    {
        StackNode* curr=top;
        StackNode *next;
        while(curr!=nullptr)
        {
            next=curr->next;
            delete curr;
            curr=next;
        }
        top=nullptr;
    }
    ~MyStack()
    {
        clear();
    }
};
int main()
{
    string input;
    MyStack stack;
    do
    {
        getline(cin,input);
        for(int i=0;i<input.length();i++)
        {
            if(input[i]>='0'&&input[i]<='9')
            {
                string number="";
                number+=input[i];
                for(i=i+1;input[i]!=' '&& i<input.length();i++)
                {
                    number+=input[i];
                }
                //cout<<number<<endl;
                int num=atoi(number.c_str());
                stack.push(num);
            }
            if((input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z'))
            {
                while(i<input.length()&&input[i]!=' ')
                {
                    i++;
                }
                cout<<"#Invalid input\n";
                
            }
            if(input[i]=='+')
            {
                int operand1=stack.pop();
                int operand2=stack.pop();
                if(operand1!=-1&&operand2!=-1)
                {
                    int sum=operand1+operand2;
                    stack.push(sum);
                }
                else if(operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                    stack.push(operand1);
                }
                else if(operand1==-1&&operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                }
            }
            if(input[i]=='*')
            {
                int operand1=stack.pop();
                int operand2=stack.pop();
                if(operand1!=-1&&operand2!=-1)
                {
                    int sum=operand1*operand2;
                    stack.push(sum);
                }
                else if(operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                    stack.push(operand1);
                }
                else if(operand1==-1&&operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                }
            }
            if(input[i]=='-')
            {
                int operand1=stack.pop();
                int operand2=stack.pop();
                if(operand1!=-1&&operand2!=-1)
                {
                    int sum=operand1-operand2;
                    stack.push(sum);
                }
                else if(operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                    stack.push(operand1);
                }
                else if(operand1==-1&&operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                }
            }
            if(input[i]=='/')
            {
                int operand1=stack.pop();
                int operand2=stack.pop();
                if(operand1!=-1&&operand2!=-1)
                {
                    if(operand2!=0)
                    {
                        int sum=operand1/operand2;
                        stack.push(sum);
                    }
                    else
                    {
                        cout<<"Division not Possible\n";
                        stack.push(operand2);
                        stack.push(operand1);
                    }
                }
                else if(operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                    stack.push(operand1);
                }
                else if(operand1==-1&&operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                }
            }
            if(input[i]=='%')
            {
                int operand1=stack.pop();
                int operand2=stack.pop();
                if(operand1!=-1&&operand2!=-1)
                {
                    int sum=operand1%operand2;
                    stack.push(sum);
                }
                else if(operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                    stack.push(operand1);
                }
                else if(operand1==-1&&operand2==-1)
                {
                    cout<<"#Not Enough arguments\n";
                }
            }
            if(input[i]=='?')
            {
                cout<<stack.toString()<<endl;
            }
            if(input[i]=='^')
            {
                cout<<stack.pop()<<endl;
            }
            if(input[i]=='&')
            {
                stack.clear();
            }
        }
    }while(input!="!");
    cout<<input<<endl;
    system("pause");
    return 0;
}
