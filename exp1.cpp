#include <bits/stdc++.h>
using namespace std;

string bitstuff(string &s){
    string header="01111110";
    string tail="01111110";
    string scpy=header;
    scpy.append(s);
    scpy.append(tail);
    s=scpy;
    
    int n=s.length();

    for(int i=8; i<n-8; i++){
        if(s[i]=='1'&&s[i-1]=='1'&&s[i-2]=='1'&&s[i-3]=='1'&&s[i-4]=='1'&&s[i-5]=='1'&&s[i-6]=='1'&&s[i-7]=='1'){
            s.insert(i+1,1, '0');
            n++;
        }
    }
    return s;
}

// string bit_destuff(string& s){
//     string scp;
//     for(int i=8; i<s.length()-8; i++){
//         char ss=s[i];
//         if(s[i]=='1'&&s[i-1]=='1'&&s[i-2]=='1'&&s[i-3]=='1'&&s[i-4]=='1'&&s[i-5]=='1'&&s[i-6]=='1'&&s[i-7]=='1'){
//             scp.push_back(ss);
//             i++;
//         }
//         else{
//             scp.push_back(ss);
//         }
//     }
//     s=scp;
//     return s;
// }

string charstuff(string &s){
    string header="01110110";
    string tail="01110110";
    string scpy=header;
    scpy.append(s);
    scpy.append(tail);
    s=scpy;
    
    int n=s.length();

    for(int i=8; i<n-8; i++){
        if(s[i]=='1'&&s[i-1]=='1'&&s[i-2]=='1'&&s[i-3]=='1'&&s[i-4]=='1'&&s[i-5]=='1'&&s[i-6]=='1'&&s[i-7]=='1'){
            s.insert(i+1,1, '0');
            n++;
        }
    }
    return s;
}

string bytestuff(string& s){
    string flag="0110";
    string escape="1101";
    //F->EF, E->EE
    string sc=s;
    for(int i=0; i<sc.length(); i++){
        if(sc[i]=='0'&&sc[i+1]=='1'&&sc[i+2]=='1'&&sc[i+3]=='0'){
            sc.insert(i, 1, '1');
            sc.insert(i+1, 1, '1');
            sc.insert(i+2, 1, '0');
            sc.insert(i+3, 1, '0');
            i+=4;
        }
        else if(sc[i]=='1'&&sc[i+1]=='1'&&sc[i+2]=='0'&&sc[i+3]=='1'){
            sc.insert(i, 1, '1');
            sc.insert(i+1, 1, '1');
            sc.insert(i+2, 1, '0');
            sc.insert(i+3, 1, '0');
            i+=4;
        }
    }
    string ssss=flag;
    ssss.append(sc);
    ssss.append(flag);
    s=ssss;
    return s;
}




int main(){
    string s="10001";
    cout<<"input: "<<s<<endl;
    cout<<"Characterstuffed: "<<charstuff(s)<<endl;
    s="10001";
    cout<<"Bitstuffed: "<<bitstuff(s)<<endl;
     s="10001";
    cout<<"Bytestuffed: "<<bytestuff(s);

}