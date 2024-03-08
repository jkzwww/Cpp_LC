
/*
Stacks 
- LIFO (last in first out)
- push, pop
*/  
#include <iostream>
#define MAX_SIZE 1000

class Stack{
    int top; //index

    public:
        int a[MAX_SIZE]; //stack storage

        Stack() { top=-1; } //init to bottom
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

// push element in if not full
bool Stack::push(int x)
{
    if(top < (MAX_SIZE-1)){
        a[++top] = x;
        std::cout << x << " pushed into stack\n";
        
        return true;
    }else{
        std::cout << "Stack Overflow!\n";

        return false;
    }
}

// pop last element out
int Stack::pop()
{
    // not empty
    if(!isEmpty()){
        // return the top element then minus index
        int x = a[top--];
        std::cout << x << " popped from stack!\n";
        return x;
    }else{
        std::cout << "Stack Underflow!\n";
        return 0;
    }
}

// peek the top element
int Stack::peek(){
    if(!isEmpty()){
        int x = a[top];
        std::cout << x << " is on top of stack!\n";
        return x;
    }
    else{
        std::cout << "Empty Stack!\n";
        return 0;
    }
}

bool Stack::isEmpty(){
    if(top >= 0)
        return false;
    else
        return true;
}

int main(){

    Stack my_stack;
    my_stack.push(5);
    my_stack.push(3);
    my_stack.push(7);

    my_stack.peek();
    my_stack.pop();

    return 0;
}