#include <iostream>
using namespace std;

class interface{
public:
    interface(){init();}
    virtual void init(){};
};

class instance: public interface{
public:
    void init(){
        cout<<"initialized"<<endl;
    }
};

int main(){
    instance i;
    return 0;
}