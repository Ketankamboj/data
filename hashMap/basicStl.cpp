#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string, int> m;

    //insertion1
    pair<string, int> p = make_pair("scorpio", 9);
    m.insert(p);

    //insertion2
    pair<string,int>p2("alto",2);
    m.insert(p2);

    //insertion3
    m["fortuner"] = 10;

    //access
    cout<<m.at("alto")<<endl;

    cout<<m["fortuner"]<<endl;

    //searching
    cout<<m.count("scorpio")<<endl;

    if(m.find("fortuner") != m.end()){
        cout<<"fortuner found"<<endl;
    }
    else{
        cout<<"fortuner not found"<<endl;
    }

    //size
    cout<<m.size()<<endl;

    //traversing
    cout<<"printing all entries"<<endl;

    for(auto i:m){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    
    return 0;
}