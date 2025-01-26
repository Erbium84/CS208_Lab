#include <bits/stdc++.h>
using namespace std;

string even_check(string s){
    string p;
    int cnt1=0, cnt2=0, cnt4=0, cnt8=0;
    for(int i=0; i<8; i+=2){
        if(s[i]=='1') cnt1++;
    }

    if(s[1]=='1') cnt2++;
    if(s[2]=='1') cnt2++;
    if(s[5]=='1') cnt2++;
    if(s[6]=='1') cnt2++;

    for(int i=3; i<=6; i++){
        if(s[i]=='1') cnt4++;
    }

    if(s[7]=='1') cnt8++;
    cnt1%=2;
    cnt2%=2;
    cnt4%=2;
    cnt8%=2;

    char out[12];
    if(cnt1==1){
        out[0]='1';
    }
    else{
        out[0]='0';
    }

    if(cnt2==1){
        out[1]='1';
    }
    else{
        out[1]='0';
    }

    if(cnt4==1){
        out[3]='1';
    }
    else{
        out[3]='0';
    }

    if(cnt8==1){
        out[7]='1';
    }
    else{
        out[7]='0';
    }

    int idx=0;
    for(int i=0; i<12; i++){
        if(i==0||i==1||i==3||i==7){
            continue;
        }
        else{
            out[i]=s[idx];
            idx++;
        }
    }

    string ans;
    for(int i=0; i<12; i++){
        ans.push_back(out[i]);
    }

    return ans;


}


string odd_check(string s){
    string p;
    int cnt1=0, cnt2=0, cnt4=0, cnt8=0;
    for(int i=0; i<8; i+=2){
        if(s[i]=='1') cnt1++;
    }

    if(s[1]=='1') cnt2++;
    if(s[2]=='1') cnt2++;
    if(s[5]=='1') cnt2++;
    if(s[6]=='1') cnt2++;

    for(int i=3; i<=6; i++){
        if(s[i]=='1') cnt4++;
    }

    if(s[7]=='1') cnt8++;
    cnt1%=2;
    cnt2%=2;
    cnt4%=2;
    cnt8%=2;

    char out[12];
    if(cnt1==1){
        out[0]='0';
    }
    else{
        out[0]='1';
    }

    if(cnt2==1){
        out[1]='0';
    }
    else{
        out[1]='1';
    }

    if(cnt4==1){
        out[3]='0';
    }
    else{
        out[3]='1';
    }

    if(cnt8==1){
        out[7]='0';
    }
    else{
        out[7]='1';
    }

    int idx=0;
    for(int i=0; i<12; i++){
        if(i==0||i==1||i==3||i==7){
            continue;
        }
        else{
            out[i]=s[idx];
            idx++;
        }
    }

    string ans;
    for(int i=0; i<12; i++){
        ans.push_back(out[i]);
    }

    return ans;


}

int main(){
    string s;
    cout<<"Enter a string of length 8: "<<endl;
    cin>>s;

    cout<<"Enter even_check received: "<<endl;
    string p;
    cin>>p;

    cout<<"Enter odd_check received: "<<endl;
    string q;
    cin>>q;

    string pp=even_check(s);
    string qq=odd_check(s);

    if(pp==p){
        cout<<"Correct even_check received"<<endl;
    }
    else{
        cout<<"Incorrect even check received"<<endl;
    }

    if(qq==q){
        cout<<"Correct odd_check received"<<endl;
    }
    else{
        cout<<"Incorrect odd check received"<<endl;
    }
    cout<<"Even sent: "<<even_check(s)<<endl;

    cout<<"Odd Sent: "<<odd_check(s)<<endl;


}