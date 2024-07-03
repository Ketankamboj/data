#include<iostream>
#include<stack>
using namespace std;
int main(){
    //creation
    stack<int> st;
    
    //insertion
    st.push(10);
    st.push(20);
    st.push(30);

    //remove
    st.pop();

    //element on top
    cout<<"element on top is: "<<st.top()<<endl;

    //size
    cout<<"size of stack is: "<<st.size()<<endl;

    //to check empty
    if(st.empty()){
        cout<<"stack is empty";
    }
    else{
        cout<<"stack is not empty";
    }
    return 0;
}