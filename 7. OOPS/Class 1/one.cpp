#include<bits/stdc++.h>
using namespace std;
class Animal{
    private: 
        int weight;
    public:
        int age;
        string name = "Tiger";

        void eat(){
            cout<<name<<" is sleeping"<<endl;
        }
        void sleep(){
            cout<<"Animal is sleeping"<<endl;
        }
        int getWeight(){
            return weight;
        }
        void setWeight(int weight){
            this->weight =  weight;
        }
};

int main(){
    Animal a1;
    a1.name = "Lion";
    a1.eat();
    a1.age = 22;
    cout<<a1.age<<endl;
    a1.eat();
    a1.sleep();
    cout<<sizeof(Animal)<<endl;

    a1.setWeight(10);
    cout<<a1.getWeight()<<endl;

    Animal* a2 = new Animal;
    (*a2).age = 25;

    (*a2).sleep();
    cout<<a2->age<<endl;
}