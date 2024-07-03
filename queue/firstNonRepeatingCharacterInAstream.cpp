#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
    string str = "aabc";
    string ans = "";
    
    int freq[26] = {0};
    queue<char> q;


    for(int i=0; i<str.length(); i++){
        char ch= str[i];

        //increment frequency
        freq[ch - 'a']++;

        //q.push
        q.push(ch);

        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }

    cout<<ans;
    return 0;
}