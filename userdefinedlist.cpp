#include <iostream>
using namespace std;

class s_record{
    public:
        string s_id;
        string name;
        double score;
        void set_data(string s1, string s2, double n);
        bool operator< (const s_record &t);
};

bool s_record::operator< (const s_record &t)
{
    if(s_id < t.s_id)
        return true;
    else
    {
        return false;
    }
}
