#include <iostream>
using namespace std;

int ReverseNum(int _num){
    int temp=0;
    int res=0;
    while(_num){
        temp=_num%10;
        res=res*10;
        res=res+temp;
        _num=_num/10;
    }
    return res;
}

int main(){
    int T=3;
    int num=0;
    while(T--){
        cin>>num;
        cout<<ReverseNum(num)<<endl;
    }
    return 0;
}