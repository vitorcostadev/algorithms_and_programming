#include <vector>
#include <iostream>

using namespace std;

vector<int> append(vector<int>, vector<int>);

int main(){
    vector<int> a = {1,2,3,4,5}, b = {5,4,3,2,1};
    vector<int> c = append(a,b);
    for(unsigned i = 0; i<c.size(); i++) cout << c[i] << " ";
}

vector<int> append(vector<int> a, vector<int> b){
    for(unsigned i = 0; i<b.size(); i++) a.push_back(b[i]);
    return a;
}