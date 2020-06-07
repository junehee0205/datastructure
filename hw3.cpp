#include <iostream>
#include <string.h>
#define SIZE 100
using namespace std;
class my_stack{
    public:
    char mystack[SIZE];
    int top=0;
    
    void push(int a){
        if(stack_full()){ printf("error!\n");
        return;}
        mystack[top] = a;
        top++;
}
    int pop() 
    {
        if(stack_empty()){ printf("error!\n");
        return 0;}
        top --;
        return(mystack[top]);
    }
    bool stack_full()
    { 
        if (top >= SIZE) {return true;}
        else {return false;}
    }
    int stack_empty() {
        if (top == 0) {return true;}
        else {return false;}
    }
    my_stack() {}
};


int main(){

my_stack s1;

s1.push("EOS");

           while ( ! s1.stack_empty( ) )

           {

             x = s1.pop( );

             cout << x << endl ; 

           }

           return 0;

}
