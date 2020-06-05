#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'
using namespace std;

class op_stack{
    char s[SIZE];
    int top;
public:
    op_stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
};

bool is_operand(char ch);
int get_precedence(char op);


int main(){
    string input, output;
    op_stack stack1;
    int i;
    char j,k,l;

    cout << "input an infix expression to convert";
    cin >> input;
    input += EOS;
    stack1.push(EOS);
    for(i=0; i<input.size(); i++){
        if(is_operand(input[i])) { output += input[i];}
        else {

            if (input[i] == '(')
            stack1.push(input[i]);

            else if (input[i] == ')'){ 
                for ( j = stack1.pop(); j != '('; j=stack1.pop()){
                    output += j;
                }
            }

            else if (input[i] == '$') {
                for ( l = stack1.pop();l !='$'; l=stack1.pop())
            output += l;
            
            }
            else{
                for ( k = stack1.pop(); get_precedence(k) >= get_precedence(input[i]); k=stack1.pop())
                {
                    output += k;
                }
                stack1.push(k);
                stack1.push(input[i]);
            }
        }
    }
    cout << output;
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

char op_stack:: top_element(){
    return(s[top-1]);
}

bool is_operand(char ch){
    if((ch =='(') || ( ch == ')') ||
        (ch == '+') || (ch == '-') ||
        (ch == '*') || (ch == '/') ||
        (ch == '%') || (ch == '$'))
        {return false;}
        else {return true;}
}

int get_precedence(char op){
    if ((op == '$') || (op == '(')) return (0);
    if ((op == '+') || (op == '-')) return (1);
    if ((op == '*') || (op == '/') || (op == '%')) return (2);
}
