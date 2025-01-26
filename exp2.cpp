#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cout<<"Enter Dataword"<<endl;
    cin>>a;
    cout<<"Enter Polynomial in binary encoding"<<endl;
    cin>>b;

    string ac=a;
    int appendd=b.length()-1;
    for(int i=0; i<appendd; i++){
        ac.push_back('0');
    }

    //now using xor to perform division

    int aa=0, bb=0;

    int exp=0;
    for(int i=ac.length()-1; i>-1; i--){
        if(ac[i]=='1'){
            aa+=pow(2,exp);
        }
        
        exp++;
    }

    exp=0;
    for(int i=b.length()-1; i>-1; i--){
        if(b[i]=='1'){
            bb+=pow(2, exp);
        }
        exp++;
    }

    int rem=aa%bb;

    for(int i=ac.length()-1; i>=ac.length()-appendd; i--){
        if(rem%2==0){
            ac[i]='0';
        }
        else{
            ac[i]='1';
        }
        rem/=2;
    }

    cout<<"String received?"<<endl;
    string c;
    cin>>c;
    if(c==ac){
        cout<<"Correct"<<endl;
    }
    else{
        cout<<"Corrupted"<<endl;
    }
    cout<<"String sent: "<<ac<<endl;
}