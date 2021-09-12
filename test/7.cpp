#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
struct item{
    int L;
    int R;
    int len;
    item(int l, int r){
        L = l;
        R = r;
        len = R-L;
    }

    bool operator > (const item&o)const{
        return len > o.len;
    }
    bool operator < (const item&o)const{
        return len < o.len;
    }

};
string& replace(string& src,const string&old_value,const string& new_value){
    for(string::size_type pos(0);pos != string::npos;pos += new_value.length()){
        if((pos = src.find(old_value,pos)) != string::npos){
            src.replace(pos,old_value.length(),new_value);
        }else{
            break;
        }
    }
        return src;
}

std::vector<std::string>split(std::string str,std::string pattern){
    std::string::size_type pos;
    std::vector<std::string> result;
    str += pattern;
    int size = str.size();
    for(int i = 0;i < size;i++){
        pos = str.find(pattern,i);
        if(pos < size){
            std::string s = str.substr(i,pos - i);
            result.push_back(s);
            i = pos + pattern.size()-1;
        }
    }
    return result;
}

int str2int(string t1){
    stringstream ss;
    int t2;
    ss<<t1;
    ss>>t2;
    return t2;
}

int main(){
    string rim;
    string input;
    cin >> rim;
    cin >> input;
    cin >> rim;
    input = replace(input,"[","");
    input = replace(input," ","");
    input = replace(input,"]","");
    vector<std::string> inputs = split(input,",");
    vector<item> section;

    for(int i = 0;i < inputs.size()/2;i++){
        section.push_back(item(str2int(inputs[i*2]),str2int(inputs[i*2+1])));
    }
    int res = 0;

    sort(section.begin(),section.end(),greater<item>());

    for(int i = 1;1 < section.size();i++){
        for(int j = 0;j < i;j++){
            if(section[i].L <= section[j].L && section[i].R <= section[j].R){
                res++;
                break;
            }
        }
    }
    cout << res;
}