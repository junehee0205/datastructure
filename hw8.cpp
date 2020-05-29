#include <iostream>
using namespace std;  

class node {
    public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};

void node::set_data(string s, double n){
    name = s;
    score = n;
}

class my_stack{
    node *top;
    public:
    my_stack();
    void push(node t);
    node pop();
    bool stack_empty();
};

my_stack::my_stack(){
    top =NULL;
}

void my_stack::push(node t){
    node *p;
    p = new node;
    (*p) = t;
    p->link = top;
    top = p;
}

node my_stack::pop(){
    if(stack_empty())
        {printf("error!\n");}
    node temp;
    temp.name = top->name;
    temp.score = top->score;
    node *t;
    t= top;
    top = top->link;
    free (t);
    return temp;
}



bool my_stack::stack_empty(){
    
    if (top == 0) {return true;}
    else {return false;}

}

class my_queue {
    node *front, *rear;
    public:
    my_queue();
    void insert_queue(node t);
    node delete_queue();
    bool queue_empty();
};

my_queue::my_queue(){
    front = NULL;
    rear = NULL;
}



int main()

{

        my_stack   a;

        node tmp;

        tmp.set_data("KIM", 22.2);

        a.push(tmp);

        tmp.set_data("LEE", 33.3);

        a.push(tmp);

        tmp.set_data("PARK", 44.4);

        a.push(tmp);

        tmp.set_data("CHOI", 55.5);

        a.push(tmp);

        tmp = a.pop();

        cout<< tmp.name << " : " << tmp.score<< "\n";

        tmp = a.pop();

        cout<< tmp.name << " : " << tmp.score<< "\n";

        return 0;

}
