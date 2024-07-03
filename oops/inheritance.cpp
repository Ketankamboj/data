#include<iostream>
using namespace std;

// single Inheritance
class Animal {
    public:
        int age;
        int weight;
        void eat(){
            cout<<"Eating"<<endl;
        }
};

class Dog: protected Animal {
    public:
    void print(){
        cout<<this->age;
    }
};

//multiple Inheritance

class fruit {
    public:
        string name;
};

class mango: public fruit{
    public:
        int weight;
};

class alphanso: public mango{
    public:
        int sweetness;
};

//multiple Inheritance

class A{
    public:
        int physics;
        int chemistry;
};

class B{
    public:
        int chemistry;
};

class C: public A, public B{
    public:
        int maths;
};

//hirarchical Inheritance

class car{
    public:
        int age;
};

class fortuner: public car{
    public:
        int speed;
};

class scorpio: public car{
    public:
        int speed;
};

int main(){
    Dog d1;
    d1.print();

    alphanso a;
    cout<<a.sweetness<<" "<<a.weight<<" "<<a.name<<endl;

    C subject;
    cout<<subject.physics<<" "<<subject.B::chemistry<<" "<<subject.maths<<endl;

    fortuner legender;
    scorpio N;
    cout<< legender.age<<" "<<N.age<<" "<<legender.fortuner::speed<<" "<<N.scorpio::speed<<endl;
    return 0;
}