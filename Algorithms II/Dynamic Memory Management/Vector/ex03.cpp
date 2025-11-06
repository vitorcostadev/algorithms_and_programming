#include <vector>
#include <iostream>

using namespace std;

void inverterVetor(vector<int> &);

int main(){
    vector<int> a = {1,2,3,4,5};
    inverterVetor(a);
    for(unsigned i = 0; i<a.size(); i++) cout << a[i] << " ";
}

void inverterVetor(vector<int> &a)
{
    for(
        unsigned i = 0, 
        j = a.size() - 1; 
        
        i<a.size()/2 and
        j>a.size()/2; 
        
        i++, j--){
        swap(a[i], a[j]);
    }
}