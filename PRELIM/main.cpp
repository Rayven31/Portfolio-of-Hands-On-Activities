#include<iostream>
#include <stack>


    int main(){

        //push 
        //pop
        //isfull
        //top
        //create an object:
        std::stack<char> stack1;

        std::cout<<"Is The stack empty? "<<stack1.empty() <<std::endl;
        stack1.push('j');
        std::cout<<"current top of The stack: "<<stack1.top() <<std::endl;
        stack1.push('i');
        std::cout<<"current top of the stack:"<<stack1.top()<<std::endl;
        stack1.push('n');
        std::cout<<"current top of The stack: "<<stack1.top() <<std::endl;
        std::cout<<"Is The stack empty? "<<stack1.empty() <<std::endl;
        std::cout<<"what is the size of the stack? "<<stack1.size() <<std::endl;

        // emplace
        stack1.emplace('n');
        std::cout << "current top of the stack after emplace: " << stack1.top() << std::endl;

        // swap
        std::stack<char> stack2;
        stack1.push('n');
        stack1.push('i');

        stack1.swap(stack2);
        std::cout << "New top of stack1 after swap: " << stack1.top() << std::endl;
        std::cout << "New top of stack2 after swap: " << stack2.top() << std::endl;


        return 0;
    }