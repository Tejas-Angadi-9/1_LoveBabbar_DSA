#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int age;
        string name;
    public:
        void setAge(int age){
            this->age = age;
        }
        void setName(string name){
            this->name = name;
        }
        int getAge(){
            return age;
        }
        string getName(){
            return name;
        }
};

int main(){
    Student* s1 = new Student;
    s1->setAge(22);
    (*s1).setName("Tejas");
    cout<<(*s1).getAge()<<" "<<(*s1).getName()<<endl;
    delete s1;
}