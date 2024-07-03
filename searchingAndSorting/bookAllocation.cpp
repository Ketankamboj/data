#include<iostream>
#include<vector>
using namespace std;
bool isPossible(vector<int> arr, int student, int mid){
        int c=1,pageSum=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>mid){
                return false;
            }
            else if(pageSum + arr[i] > mid){
                c++;
                pageSum = arr[i];
                if(c>student){
                    return false;
                }
            }
            else{
                pageSum += arr[i];
            }
        }
        return true;
    }
int main(){
    int book,student;
    
    cout<<"enter no of books: ";
    cin>>book;

    cout<<"enter no of student: ";
    cin>>student;
    
    vector<int>arr(book);
    for(int i=0; i<arr.size(); i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    int start=0,end=0,ans;
    for(int i=0; i<arr.size(); i++){
        end+=arr[i];
    }
    if(student>book){
        cout<<"can not allot books.";
    }
    else{
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isPossible(arr,student,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
    }

    cout<<"the minimum allot books pages are: "<<ans;
    return 0;
}