#include<iostream>
using namespace std;

//compile time polymorphism
   //function overloading
class maths{
    public:
        int sum(int a, int b){
            return a+b;
        }

        int sum(int a, int b, int c){
            return a+b+c;
        }

        int sum(int a, float b){
            return a+b;
        }
};

    //operator overloading

class param{
    public:
        int val;

        void operator+(param& obj2){
            int value1 = this->val;
            int value2 = obj2.val;
            cout<<(value2-value1)<<endl;
        }
};

// run time polymorphism

class Animal{
    public:
        virtual void speak(){
            cout<<"speaking"<<endl;
        }
};
// function overriding
class Dog: public Animal{
    public:
        void speak(){
            cout<<"bark"<<endl;
        }
};

int main(){
    maths obj;
    cout<<obj.sum(2,5)<<" "<<obj.sum(1,2,3)<<" "<<obj.sum(2,5.12f)<<endl;

    param obj1, obj2;
    obj1.val = 7;
    obj2.val = 2;
    obj1 + obj2;

    Animal a;
    a.speak();
    Dog b;
    b.speak();

    // upcasting
    Animal* c = new Dog();
    c->speak();

    //down casting
    Dog* d = (Dog*)new Animal();
    d->speak();
    return 0;
}