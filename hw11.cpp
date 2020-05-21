#include <iostream>
using namespace std;
#define INSERT 1
#define DELETE 2
#define SHOW_FRONT 3
#define QUIT 4


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
        node front_element();
        bool empty();
};

class my_list{
    node *head, *tail;
    public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    void invert();
    friend bool list_equal(my_list a, my_list b);
};

int get_a_cmd();
void node_insert(my_queue & a);
void node_delete(my_queue &a);
void show_front(my_queue &a);
void node_invert(my_queue &a);


int main()

{
    my_queue a;
    int cmd;
    do{
        cmd = get_a_cmd();
        switch(cmd){
            case INSERT: node_insert(a);
                break;
            case DELETE: node_delete(a);
                break;
            case SHOW_FRONT: show_front(a);
                break;
            case QUIT:
                cout << "Bye!!\n\n";
        }
    }while(cmd != QUIT);

    return 0;
}

int get_a_cmd(){
    int menu;
    cout << "1. Insert a node\n";
    cout << "2. Delete a node\n";
    cout << "3. Show the front element\n";
    cout << "4. Quit\n";
    cout << "5. Invert\n";
    cout << "Select a command: ";
    cin >> menu;
    return menu;
}

void node_insert(my_queue &a){
    node tmp;
    string tname;
    double tscore;

    cout << "Name: ";
    cin >> tname;
    cout << "Score: ";
    cin >> tscore;
    tmp.set_data(tname, tscore);
    a.insert_q(tmp);
}

void node_delete(my_queue &a){
    node tmp;

    if(a.empty()){
        cout << "The queue is empty.\n";
        return ;
    }

    tmp = a.delete_q();
    cout << "The node delete:\n";
    cout << tmp.name << ":" << tmp.score << "\n";
}

void show_front(my_queue &a){
    node tmp;

    if(a.empty()){
        cout << "The queue is empty.\n";
        return;
    }

    tmp = a.front_element();
    cout << "The front element:\n";
    cout << tmp.name<< ":" << tmp.score << "\n";
}


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

node my_queue::front_element(){

    if(!empty())
        return (*front);
    else
            cout << "ERROR: queue empty\n\n";
}

bool my_queue::empty(){
    if (front == NULL) return true;
    else return false;
    
}

my_list::my_list(){
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t){
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if(tail == NULL)
        tail = p;
}

void my_list::add_to_tail(node t){
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(tail != NULL)
        tail->link = p;
    else
        head =p;
    tail = p;
}

node my_list::delete_from_head(){
    node temp;
    node *t;
    t= head;
    temp = *head;
    head = head->link;
    delete t;
    if(head==NULL)
        tail = NULL;
    return temp; 
}

int my_list::num_nodes(){
    node *t;
    int count =0;
    for(t=head; t!=NULL; t=t->link)
        count++;
    return count;
}

bool my_list::list_empty(){
    if(head == NULL)
        return true;
    else
    {
            return false;
    }
}

void my_list::invert(){
    
    node *tmp, *newhead, *oldhead;

    newhead = NULL;
    oldhead = head; 

    while(oldhead){
        tmp = newhead;
        newhead = oldhead;
        oldhead  = oldhead->link;
        newhead->link = tmp;
    }
    tail = head;
    head = newhead;
}


bool equal_data(node t1, node t2)
{
    if(t1.name != t2.name)
        return false;
    else if(t1.score != t2.score)
        return false;
    else return true;
}

bool is_equal(node *p1, node *p2){
    if((p1==NULL) && (p2 == NULL))
        return true;
    else if((p1==NULL) || (p2 == NULL))
        return false;
    else if(equal_data(*p1, *p2))
        return(is_equal(p1->link, p2->link));
    else
        return false;
}

bool list_equal(my_list a, my_list b){
    return is_equal(a.head, b.head);
}
