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

class my_queue{
        node *front;
        node *rear;
    public:
        my_queue();
        void insert_q(node t);
        node delete_q();
        bool empty();
};

my_queue:: my_queue()
{
    front = NULL;
    rear = NULL;
}


void my_queue::insert_q(node t)
{
    node* p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if (rear != NULL) {
        rear->link = p;
    }
    else {
        front = p;
    }
    rear = p;
}

node my_queue::delete_q()
{
    if(empty())
        {printf("error!\n");}
    node tmp;
    tmp.name = front->name;
    tmp.score = front->score;
    node *t;
    t=front;
    front = front->link;
    free(t);
    return tmp;
}

bool my_queue::empty(){
    if (front == NULL) return true;
    else return false;
    
}

int main()

{

    my_queue  a;

    node tmp;

    tmp.set_data("KIM", 22.2);

    a.insert_q(tmp);

    tmp.set_data("LEE", 33.3);

    a.insert_q(tmp);

    tmp.set_data("PARK", 44.4);

    a.insert_q(tmp);

    tmp.set_data("CHIO", 55.5);

    a.insert_q(tmp);

    tmp = a.delete_q();

    cout << tmp.name << " : " << tmp.score <<"\n";

    tmp = a.delete_q();

    cout << tmp.name << " : " << tmp.score <<"\n";

    return 0;

}
