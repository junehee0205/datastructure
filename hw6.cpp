#include <iostream>
#include <string>
#include <cmath>
#define Q_SIZE 100
using namespace std;

class element {
        public:
        string sname;
        string phone_no;
        void set_data(string s1, string s2);
};

class my_queue{
        element q[Q_SIZE];
        int front, rear;
        public:
        my_queue();
        void insert_q(element x);
        element delete_q();
        bool full();
        bool empty();
};





int main()
{
        my_queue  a;
        element  tmp;

        tmp.set_data("KIM", "010-1234-5678");
        a.insert_q(tmp);
        tmp.set_data("LEE", "010-1357-2468");
        a.insert_q(tmp);
        tmp.set_data("PARK", "010-9876-5432");
        a.insert_q(tmp);

        while (!a.empty() ) {
                tmp = a.delete_q();
                cout << tmp.sname << " : " << tmp.phone_no<< "\n";
        }
        return 0;
}

my_queue:: my_queue()
        {
                front=0;
                rear =0;
        }

void my_queue::insert_q(element x)
{
        if (!full()){
                q[rear] = x;
                rear = (rear+1) % Q_SIZE;
        }
}

element my_queue::delete_q()
{
        element tmp;
        if(!empty()){
                tmp = q[front];
                front = (front+1) % Q_SIZE;
                return (tmp);
        }
}

bool my_queue::full()
{
        if((rear+1)% Q_SIZE == front)
                return true;
        else 
                return false;
}

bool my_queue::empty()
{
        if (rear == front)
                return true;
        else 
                return false;
}

void element::set_data(string s1, string s2)
{
        sname = s1;
        phone_no = s2;
}
