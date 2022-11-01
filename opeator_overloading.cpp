#include <iostream>
using namespace std;
class complexc{
    private:
        int a,b;
    public:
        complexc(int a,int b){
            this->a=a;
            this->b=b;
        }
        complexc(){}
        complexc operator+(complexc c){
            complexc temp;
            temp.a=a+c.a;
            temp.b=a+c.b;
            return temp;
        }
        void show(){
            cout<<a<<" "<<b<<endl;
        }
};
int main()
{
    complexc  c1(2,3),c2(5,6),c3;
    c3=c1.operator+(c2);
    c3.show();
    return 0;
}
