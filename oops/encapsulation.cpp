#include<iostream>
using namespace std;

class Animal{
    private:
        int age;
        int weight;

    public:
        void eat(){
            cout<<"eating"<<endl;
        }

        int getAge(){
            return this->age;
        }
        int setAge(int age){
            this->age = age;
        }
};

int main(){

    return 0;
}