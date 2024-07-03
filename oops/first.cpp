#include<iostream>
using namespace std;

class Animal {
    //state or properties
    private:
    int weight;
    public:
    string name;
    int age;

    //default constructor

    Animal(){
        this->weight = 0;
        this->age = 0;
        this-> name = "";
        cout<<"contructor called"<<endl;
    }
    //parametrised constructor
    Animal(int age){
        this->age = age;
        cout<<"parametrised contructor called"<<endl;
    }

    //copy constructor
    Animal( Animal& obj){
        this->age = obj.age;
        this->weight = obj.weight;
        this->name = obj.name;
    }

    //behaviour
    void eat(){
        cout<<"eating";
    }

    void sleep(){
        cout<<"sleeping";
    }

    //getter
    int getWeight(){
        return weight;
    }

    //setter
    void setWeight(int weight){
        this->weight = weight;
    }
    
    //destructor
    ~Animal(){
        cout<<"i am inside destructor"<<endl;
    }
};

int main(){
    //object creation

    //static
    Animal ramesh(19);
    ramesh.age = 12;
    ramesh.name = "lion";
    cout<<"age is: "<<ramesh.age<<endl;
    cout<<"name is: "<<ramesh.name<<endl;

    ramesh.eat();
    cout<<endl;
    ramesh.sleep();
    cout<<endl;

    ramesh.setWeight(100);
    cout<<"weight: "<<ramesh.getWeight()<<endl;

    // dynamic allocation
    Animal* suresh = new Animal(10);
    (*suresh).age = 5;
    (*suresh).name = "billi";

    suresh->eat();
    suresh->sleep();

    //object copy
    Animal c = ramesh;

    //manually destructing
    delete suresh;
    return 0;
}