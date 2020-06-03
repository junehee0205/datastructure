#include <iostream>
#include <string>
#include <cmath>
#define SIZE 100
using namespace std;

class op_stack{
    int top;
public:
    char s[SIZE];
    op_stack();
    void push(char x);
    char pop();
    bool empty();
};


int main(){

    op_stack s1, s2;
    int i=0;
    string comp1, comp2;
    string input;
    char buff[100];
    cin.getline(buff, 80);
    input = buff;
    int len = input.size();
    for(i=0; i<floor(len/2.0); i++){
        s1.push(input[i]);
    }
    for (i= ceil(len/2.0); i<len; i++){
        s2.push(input[i]);
    }
    for (i= ceil(len/2.0); i<len; i++){
        char j = s2.pop();
        comp2 += j;
    }
    if( s1.s == comp2){
        cout << "Yes, it's a palindrome\n";
    }
    else{ cout << "No, It's not a palindrome\n";}
}

op_stack::op_stack() {
    top =0;
}

void op_stack:: push(char x){
    s[top] = x;
    top++;
}

char op_stack:: pop(){
    top--;
    return(s[top]);
}

bool op_stack::empty(){
    return (top ==0);
}
