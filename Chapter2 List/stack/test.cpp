#include <iostream>
using namespace std;
template<typename T>
class STACK{
    private:
    int top;
    T s[105];
    public:
    STACK(){top = 0;}
    void push(T x){s[++top] = x;}
    T top(){return s[top];}
    void pop(){--top;}
};
int main(){
    STACK<char> s1;
    STACK<int> s2;
    return 0;
}