#include<iostream>
using std::string;

bool contain_cap(const string& s){
    for (auto c : s){
        if (isupper(c)) return true;
    }
    return false;

}

void to_lowercase(string& s){
    for (auto& c : s) c = tolower(c);
}

int main(){
    string s ("This is the test string.");
    std::cout << contain_cap(s) << std::endl;
    to_lowercase(s);
    std::cout << s << std::endl;

    return 0;
}
