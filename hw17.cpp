#include <iostream>
using namespace std;

class bst_node{
    public:
            string s_id;
            string name;
            double score;
            bst_node *left, *right;
            bst_node();
            bst_node(string s1, string s2,  double n);
            void set_data(string s1, string s2, double n);
};

class bst_tree{
    bst_node *root;
    int csize;
    public:
        bst_tree();
        void insert_node(bst_node t);
        void show_inorder();
        bst_node search(string tid);
};

bst_node::bst_node()
{
    s_id = "";
    name = "";
    score = 0;
}

bst_node::bst_node(string s1, string s2,  double n)
{
    s_id= s1;
    name = s2;
    score = n;
}

void bst_node::set_data(string s1, string s2, double n)
{
    s_id = s1;
    name = s2;
    score = n;
}

bst_tree::bst_tree(){
    root = NULL;
    csize =0;
}

void bst_tree::insert_node(bst_node t){
    bst_node *p;
    bst_node *tmp;

    tmp = new bst_node;
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;

    if(root ==NULL){
        root = tmp;
        return;
    }

    p = root;
    while(1)
    {
        if(p->s_id == t.s_id)
        {
            cout << "Insertion Failed: the Key" << t.s_id << "already exists." << endl;
            return;
        }
        if(p->s_id < t.s_id)
        {
            if (p->right == NULL)
            {
                p->right = tmp;
                return;
            }
            else p = p->right;
        }
        else
        {
            if(p->left == NULL)
            {
                p->left = tmp;
                return;
            }
            else p = p->left;
        }
    }
}

void inorder_print(bst_node *p){
    if(p==NULL) return;

    inorder_print(p->left);
    cout << p->s_id << " : "<< p->name << ":" << p->score << "\n";
    inorder_print(p->right);
}

void bst_tree::show_inorder()
{
    inorder_print(root);
}

bst_node bst_tree::search(string tid)
{
    bst_node *p;
    p = root;
    if(root == NULL)
    {
        bst_node tmp;
        tmp.set_data("000000000", "Nonde", -1);
        cout << "The key " << tid << " does not exist.\n";
        return tmp;
    }
    while(1)
    {
        if(p->s_id == tid)  return (*p);
        if(p->s_id < tid)
        {
            if(p->right == NULL)
            {
                bst_node tmp;
                tmp.set_data("000000000", "Nonde", -1);
                cout << "The key " << tid << " does not exist.\n";
                return tmp;
            }
            else p = p->right;
        }
        else
        {
            if(p->left == NULL)
            {
                bst_node tmp;
                tmp.set_data("000000000", "Nonde", -1);
                cout << "The key " << tid << " does not exist.\n";
                return tmp;
            }
            else p = p->left;
        }
    }
}

int main()
{
bst_node temp;
bst_tree t1;
        temp.set_data("21900013", "Kim", 6.5);
        t1.insert_node(temp);
        temp.set_data("21900136", "Lee", 8.8);
        t1.insert_node(temp);
        temp.set_data("21900333", "Park", 9.2);
        t1.insert_node(temp);
        temp.set_data("21800442", "Choi", 7.1);
        t1.insert_node(temp);
        temp.set_data("21900375", "Ryu", 5.4);
        t1.insert_node(temp);
        temp.set_data("21700248", "Cho", 6.3);
        t1.insert_node(temp);
        cout << "\n\n Node List : inorder sequence \n";
        t1.show_inorder();
        string s_key = "21800442";
        temp = t1.search(s_key);
        cout << "\n -- " << s_key << "\'s record ---" << endl;
        cout << " Student ID   : "<< temp.s_id << endl;
        cout << " Student Name : "<< temp.name << endl;
        cout << " Score  : " << temp.score << endl;

        return 0;

}
