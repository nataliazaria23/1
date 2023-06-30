#include <iostream>

class Base{
public:
    virtual void print() const = 0;
};

class DerivedA : public Base{
public:
    void print() const {
        std::cout << "A" << std::endl;
    }
};

class DerivedB : public Base{
public:
    void print() const {
        std::cout << "B" << std::endl;
    }
};

class PolyArray{
private:
    Base** all;
    int size;
    int count;

public:
    PolyArray(int val){
        size = val;
        Base **all = new Base* [size];
        count = 0;
    }
    PolyArray(const PolyArray &other){
        this->size = other.size;
        this->count = other.count;
        Base **all = new Base* [size];
        for(int i = 0; i < count; i ++){
            this->all[i] = other.all[i];
        }
    }
    ~PolyArray(){
        delete[]all;
    }
    void push_back(Base* value){
        all[count] = value;
        count++;
    }
    int Size(){
        return size;
    }
    Base* get(int val){
        return all[val];
    }
};

int main(){
    int size = 4;
    PolyArray array(size);
    array.push_back(new DerivedA);
    array.push_back(new DerivedB);
    array.push_back(new DerivedA);
    array.push_back(new DerivedB);
    for(int i = 0; i < array.Size(); i ++){
        array.get(i)->print();
    }
    return 0;
}

