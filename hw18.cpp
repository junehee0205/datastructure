#include <iostream>
using namespace std;

class bst_node{
    public:
            string name;
            string p_num;
            string b_day;
            bst_node *left, *right;
            bst_node();
            bst_node(string s1, string s2,  string s3);
            void set_data(string s1, string s2,  string s3);
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
    name = "";
    p_num = "";
    b_day = "";
}

bst_node::bst_node(string s1, string s2,  string s3)
{
    name = s1;
    p_num = s2;
    b_day = s3;
}

void bst_node::set_data(string s1, string s2,  string s3)
{
    name = s1;
    p_num = s2;
    b_day = s3;
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
        if(p->name == t.name)
        {
            cout << "Insertion Failed: the Key" << t.name<< "already exists." << endl;
            return;
        }
        if(p->name < t.name)
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
    cout << p->name << " : " << p->p_num << " , " << p->b_day << "\n";
    inorder_print(p->right);
}

void bst_tree::show_inorder()
{
    inorder_print(root);
}

bst_node bst_tree::search(string tname)
{
    bst_node *p;
    p = root;
    if(root == NULL)
    {
        bst_node tmp;
        tmp.set_data("Nonde", "00000000000", "00000000");
        cout << "The key " << tname << " does not exist.\n";
        return tmp;
    }
    while(1)
    {
        if(p->name == tname)  return (*p);
        if(p->name < tname)
        {
            if(p->right == NULL)
            {
                bst_node tmp;
                tmp.set_data("Nonde", "00000000000", "00000000");
                cout << "The key " << tname << " does not exist.\n";
                return tmp;
            }
            else p = p->right;
        }
        else
        {
            if(p->left == NULL)
            {
                bst_node tmp;
                tmp.set_data("Nonde", "00000000000", "00000000");
                cout << "The key " << tname << " does not exist.\n";
                return tmp;
            }
            else p = p->left;
        }
    }
}

int selectMenu() {
	int menu;
   	cout << "1. 원소 추가\n";
    cout << "2. 원소 조회\n";
    cout << "3. 전체 목록 보기\n";
    cout << "4. 종료\n\n";
    cout << "              명령 :";
    cin >> menu;
    return menu;
}



int main()
{
    bst_node temp;
    bst_tree t1;
    temp.set_data( "Kim", "01011516144", "20020202");
    t1.insert_node(temp);
    temp.set_data("Lee",  "01021516144", "20010101");
    t1.insert_node(temp);
    temp.set_data( "Park",  "01031516144", "20001212");
    t1.insert_node(temp);
    temp.set_data("Choi",  "01041516144", "19991111");
    t1.insert_node(temp);
    temp.set_data( "Ryu",  "01051516144", "19981231");
    t1.insert_node(temp);

    while (1){
        int menu = selectMenu();
        if (menu == 1)
        {
            string a, b, c;
            cout << "이름?: ";
            cin >> a;
            cout << "전화번호?: ";
            cin >> b;
            cout << "생년월일?(8자): ";
            cin >> c;
            temp.set_data(a, b, c);
            t1.insert_node(temp);
        }
        if (menu == 2)
        {
            string s_key;
            cout << "이름으로 검색: ";
            cin >> s_key;
            temp = t1.search(s_key);
            if(temp.name == s_key){
                cout << "\n -- " << temp.name << "\'s record ---" << endl;
                cout << " Name   : "<< temp.name << endl;
                cout << " Phone Number : "<< temp.p_num << endl;
                cout << " Birthday  : " << temp.b_day << endl;
            }
        }
        if (menu ==3)
        {
            cout << "\n\nNode List : inorder sequence \n";
            t1.show_inorder();
        }

        if (menu == 4) break;
    }
    printf("종료됨!\n");
    return 0;
}
