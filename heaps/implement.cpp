#include<iostream>
using namespace std;

class heap{
    public:
    int arr[11];
    int size;

    heap(){
        size = 0;
    }

    void insert(int value){
        // value insert kro end mee
        size++;
        int index = size;
        arr[index] = value;

        // shi jangha leke jao
        while(index > 1){
            int parentIndex = index/2;

            if(arr[index] > arr[parentIndex]){
                swap(arr[index] , arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void deleteRoot(){
        //replace root node value with last node value
        arr[1] = arr[size];
        size--;

        //place root node ka data on its correct position
        int index = 1;
        while(index < size){
            int left = 2*index;
            int right = 2*index+1;

            int largest = index;

            if(left < size && arr[largest] < arr[left]){
                largest = left;
            }
            if(right < size && arr[largest] < arr[right]){
                largest = right;
            }

            if(largest == index){
                //value is at correct position
                break;
            }
            else{
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
    }
};

int main(){
    heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    for(int i=0; i<=h.size; i++){
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;

    h.insert(110);

    cout<<"after insertion"<<endl;
    for(int i=0; i<=h.size; i++){
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}