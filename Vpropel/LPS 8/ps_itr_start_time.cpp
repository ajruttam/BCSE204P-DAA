#include<iostream>
using namespace std;
#include<queue>
#include<set>
class activity{
    public:
    string name;
    int start;
    int finish;
    friend istream& operator>>(istream&,activity&);
    friend ostream& operator<<(ostream&,const activity&);
    bool operator<(const activity&) const;
};
istream& operator>>(istream& in, activity& a){
    in>>a.name>>a.start>>a.finish;
}
ostream& operator<<(ostream& out, const activity& a){
    out<<a.name<<" ";
}
bool activity::operator<(const activity& a) const{
    if(a.start != start)return a.start>start;
    else return a.finish > finish;
}
void iterative_activity_selector(priority_queue<activity> &pq,vector<activity> &v){
    activity a;
    a = pq.top();
    pq.pop();
    v.push_back(a);
    while(!pq.empty()){
        if(pq.top().finish<=a.start){
            a = pq.top();
            v.push_back(a);
        }
        pq.pop();      
    }
}
int main(){
    priority_queue<activity> pq;
    int n,i;
    activity a;
    vector<activity> v;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        pq.push(a);
    }
    iterative_activity_selector(pq,v);
    for(int i = v.size()-1; i>=0;i--)
        cout<<v[i];
}
