#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class s_record{
    public:
        string s_id;
        string name;
        string major;
        double score;

    static bool comp_sid(const s_record & s1, const s_record & s2){
        if(s1.s_id < s2.s_id)
            return true;
        return false;
    }

    static bool comp_major(const s_record &s1, const s_record &s2){
        if(s1.major < s2.major)
            return true;
        return false;
    }
};

int main(void)
{
    vector <int> a;
    vector <int>::iterator p1, p2;
    vector <s_record> s_list = {{"21900013", "Kim", "CS", 6.5}, {"21900136", "Lee", "EE", 8.8}, {"21900333", "Park", "CS", 9.2}, {"21800442", "Choi", "DM", 7.1}, {"21900375", "Ryu", "DM", 5.4}, {"21700248", "Cho", "EE", 6.3}, {"21700302", "Jung", "EE", 8.3}, {"21800255", "Han", "DM", 6.9},{"21800369", "Kang", "CS", 7.3}, {"21900401", "Yang", "EE", 9.1}, {"21800123", "Moon", "CE", 8.1}, {"21700678", "Seo", "CS", 7.9}};

    
    sort(s_list.begin(), s_list.end(), s_record::comp_sid);
    for(unsigned k=0; k<s_list.size(); k++)
        cout << s_list[k].s_id << ":" << s_list[k].name << ":" << s_list[k].major << ":" << s_list[k].score <<endl;
    cout << "\n";
    stable_sort(s_list.begin(), s_list.end(), s_record::comp_major);

    for(unsigned k=0; k<s_list.size(); k++)
        cout << s_list[k].s_id << ":" << s_list[k].name << ":" << s_list[k].major << ":" << s_list[k].score << endl;
}
