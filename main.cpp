#include <iostream>
#include <string>
#include <cassert>

using std::string;
class Person
{
private:
    string name_;
    int age_;
public:
    Person(){
        name_ = "-";
        age_ = 0;
    }
   Person( string name, int age)
   {
       this->name_ = name;
       this->age_ = age;
   }
   string getName() const{
       return  name_;
    }
   int getAge() const{
        return age_;
    }
};

class People {
private:
    Person all[10] = {
            Person( )
    };
    static int count;
public:
    void addPerson(Person a){
        all[count] = a;
        count++;
    }
    int getNumPeople(){
        return count;
    }
    Person getOldestPerson(){
        Person a;
        int max = 0;
        for(int i = 0; i < count; i ++){
            if(all[i].getAge() >= max) {
                a = all[i];
                max = all[i].getAge();
            }
        }
        return a;
    }
    Person getYoungestPerson(){
        Person a;
        int min = 1111;
        for(int i = 0; i < count; i ++){
            if(all[i].getAge() <= min && all[i].getAge() != 0) {
                a = all[i];
                min = all[i].getAge();
            }
        }
        return a;
    }
};
 int People::count = 0;

int main() {
    People people;
    people.addPerson(Person("Alice", 20));
    people.addPerson(Person("Bob", 30));
    people.addPerson(Person("Carol", 25));
    assert(people.getNumPeople()==3);
    assert(people.getOldestPerson().getName() == "Bob");
    assert(people.getYoungestPerson().getName() == "Alice");
    return 0;
}
