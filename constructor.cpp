#include <iostream>
using namespace std;
class Complex{
    int a,b;
    public:
        Complex(int a,int b){
            this->a=a;
            this->b=b;
        }
        void show(){
            cout<<a<<" "<<b<<endl;
        }
};
int main(){
    Complex c(2,3);
    c.show();
    return 0;
}