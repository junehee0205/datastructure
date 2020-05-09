#include <iostream>
using namespace std;
#define HSIZE 100
class element{
    public:
    string name;
    double score;
    void set_data(string n, double s);
};

void element::set_data(string n, double s)
{
    name = n;
    score = s;
}

class my_heap{
    element h[HSIZE];
    int csize;
    public:
    my_heap();
    my_heap(element a[], int n);
    int h_size();
    void insert_heap (element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    void adjust(int t_root);
    double score_sum();
    double score_average();
    int node_delete_by_name(string tname);
};

my_heap::my_heap()
{
    csize = 0;
}

my_heap::my_heap(element a[], int n)
{
    int k;

    for(k=1; k <= n; k++){
        h[k] = a[k-1];
        csize = n;
    }
    for( k = n/2; k>=1; k--)
        adjust (k);

}

bool my_heap::heap_empty()
{
    if(csize == 0)
        return true;
    else
        return false;
}

bool my_heap::heap_full()
{
    if(csize >= HSIZE -1)
        return true;
    else
    {
        return false;
    }
}

int my_heap::h_size()
{
    return csize;
}

void my_heap::insert_heap(element t)
{
    int k;
    csize ++;
    k = csize;
    while((k != 1) && (t.score > h[k/2].score))
    {
        h[k] = h[k/2];
        k /= 2;
    }
    h[k] = t;
}

element my_heap::delete_heap()
{
    element t;
    element tmp;
    int parent, child;

    t= h[1];
    tmp = h[csize];
    csize--;
    parent = 1;
    child = 2;
    while(child < csize) {
        if((child < csize && h[child].score < h[child +1].score))
            child++;
        if(tmp.score >= h[child].score)
            break;
        h[parent] = h[child];
        parent = child;
        child *= 2;
    }
    h[parent] = tmp;
    return t;
}

void my_heap::adjust(int t_root)
{
    double tmpkey;
    int child;
    element tmp;

    tmp = h[t_root];
    tmpkey = h[t_root].score;
    child = 2* t_root;

    while(child <= csize){
        if((child < csize) && (h[child].score < h[child +1].score))
            child ++;
        if(tmpkey > h[child].score)
            break;
        else{
            h[child / 2] = h[child];
            child *= 2;
        }
    }
    h[child / 2] = tmp;
}

double summation(element a[], int troot, int n)
{
    if(troot>n)
        return 0;
    return (a[troot].score + summation(a,2*troot,n) + summation(a, 2*troot+1, n));
}

double my_heap::score_sum()
{
    return summation(h,1,csize);
}

double my_heap::score_average()
{
    if (csize ==0) return 0;
    return score_sum() / csize;
}

void heap_adjust(element a[], int troot, int size){

    element temp;
    for(int i=troot; i<size; i++){
        
        if(a[i].score < a[i+1].score){
            
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
}

int delete_node(element a[], int troot, string tname, int n)
{
    element tmp;
    if(troot>n)
        return 0;
    if(a[troot].name == tname){
        tmp = a[troot];
        a[troot] = a[n];
        a[n] = tmp;
        heap_adjust(a, troot, n-1);
        return 1;
    }
    else{
        if (delete_node(a, 2*troot, tname, n) == 1)
            return 1;
        else
        {
            return delete_node(a, 2*troot+1, tname, n);
        }
    }
}

int my_heap::node_delete_by_name(string tname)

{
    if(csize == 0)
        return 0;
    if(delete_node(h ,1,tname, csize) == 1)
    {
        csize--;
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{

    element temp;
   element      a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85}  };
   my_heap   h1(a, 6);
   cout << "Number of nodes : " << h1.h_size() << endl;
   cout << "Score Sum = " << h1.score_sum() << endl;
   cout << "Score average = " << h1.score_average() << endl;
   h1.node_delete_by_name("Kim");
   cout << "\n-- After the deletion operation. --\n\n";
   cout << "Number of nodes : " << h1.h_size() << endl;
   cout << "Score Sum = " << h1.score_sum() << endl;
   cout << "Score average = " << h1.score_average() << endl;
   while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
   }
   return 0;
}
