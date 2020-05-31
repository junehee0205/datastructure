#include <iostream>
using namespace std;
#define SIZE 100

class s_record{
    public:
        string s_id;
        string s_name;
        double s_score;
        s_record();
        s_record(string s1, string s2, double n);
};

s_record::s_record()
{
    s_id: "";
    s_name: "";
    s_score = 0;
}

s_record::s_record(string s1, string s2, double n)
{
    s_id = s1;
    s_name = s2;
    s_score = n;
}

class my_heap{
    s_record h[SIZE];
    int csize;
    public:
    my_heap();
    my_heap(s_record a[], int n);
    int h_size();
    void insert_heap (s_record t);
    s_record delete_heap();
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

my_heap::my_heap(s_record a[], int n)
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
    if(csize >= SIZE -1)
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

void my_heap::insert_heap(s_record t)
{
    int k;
    csize ++;
    k = csize;
    while((k != 1) && (t.s_id > h[k/2].s_id))
    {
        h[k] = h[k/2];
        k /= 2;
    }
    h[k] = t;
}

s_record my_heap::delete_heap()
{
    s_record t;
    s_record tmp;
    int parent, child;

    t= h[1];
    tmp = h[csize];
    csize--;
    parent = 1;
    child = 2;
    while(child < csize) {
        if((child < csize && h[child].s_id < h[child +1].s_id))
            child++;
        if(tmp.s_id >= h[child].s_id)
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
    string tmpkey;
    int child;
    s_record tmp;

    tmp = h[t_root];
    tmpkey = h[t_root].s_id;
    child = 2* t_root;

    while(child <= csize){
        if((child < csize) && (h[child].s_id < h[child +1].s_id))
            child ++;
        if(tmpkey > h[child].s_id)
            break;
        else{
            h[child / 2] = h[child];
            child *= 2;
        }
    }
    h[child / 2] = tmp;
}



void adjust(s_record a[], int troot, int size){

    s_record temp;
    for(int i=troot; i<size; i++){
        
        if(a[i].s_id < a[i+1].s_id){
            
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
}

int delete_node(s_record a[], int troot, string tname, int n)
{
    s_record tmp;
    if(troot>n)
        return 0;
    if(a[troot].s_name == tname){
        tmp = a[troot];
        a[troot] = a[n];
        a[n] = tmp;
        adjust(a, troot, n-1);
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

void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4);

void quick_sort(s_record a[], int left, int right);
void heap_sort(s_record a[], int n);
void merge_sort(s_record a[],int n);
void show_thelist(s_record a[], int n);


int main()
{
      s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
                                  { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
                 { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
                 { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
      int    n = 12;     

    //quick_sort(s_list, 0, n-1);
    //heap_sort(s_list, n);
    //merge_sort(s_list, n); 

      cout << "< The result of the sorting >" << endl;
      show_thelist(s_list, n);

      return 0;

}

void quick_sort(s_record a[], int left, int right)
{
    s_record pivot, temp;
    int i, j;
    if(left >= right) return;
    i = left;
    j = right+1;
    pivot = a[left];
    while(i <j){
        while ((i<=right) && (a[i].s_id < pivot.s_id)){
            i++;
        }
        while(a[j].s_id > pivot.s_id){
            swap(a[i],a[j]);
        }
    }
    swap(a[left],a[j]);
    quick_sort(a,left,j-1);
    quick_sort(a,j+1,right);
}

void heap_sort(s_record a[], int n)
{

    int i;
    s_record temp;
    
    int size = n-1;
    for(i=(size-1)/2; i>=0; i--)
    {
        adjust(a,i,size);
    }
    for(i=size-1; i>=0; i--)
    {
        temp = a[0];
        a[0] = a[i+1];
        a[i+1] = temp;
        adjust(a,0,i);
    }
}

void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4)
{
    int i,j,k,t;
    i=n1;
    j=n3;
    k=n1;
    while((i<=n2) && (j<=n4))
    {
        if(a[i].s_id <= a[j].s_id)
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if(i> n2)
        for(t=j; t<=n4; t++)
            b[t] = a[t];
    else   
        for(t=i; t<=n2; t++)
            b[k+t-i] = a[t];
}
void merge_pass(s_record a[], s_record b[], int n, int s)
{
    int i, j;
    for(i=0; i<(n - 2*s + 1); i+=2*s)
        merge(a,b,i,i+s-1, i+s, i+2*s-1);
    if(i+s <= n)
        merge(a,b,i,i+s-1, i+s, n);
    else
        for(j=i; j<=n; j++)
            b[j] = a[j];
}

void merge_sort(s_record a[], int n)
{
    int s = 1;
    s_record b[SIZE];

    while(s < n){
        merge_pass(a, b, n-1, s);
        s *=2;
        merge_pass(b,a,n-1,s);
        s*=2;
    }
}

void show_thelist(s_record a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << a[i].s_id << " : ";
        cout << a[i].s_name << " : ";
        cout << a[i].s_score << endl;
    }
}
