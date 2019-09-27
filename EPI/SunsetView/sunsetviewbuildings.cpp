#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> func_sunsetview(vector<int>& buildings){
    if(buildings.empty())
        throw string("Buildings are empty");
    int index =0;
    int height =0;
    stack<pair<int,int>> sunsetApp;
    vector<int>::iterator itr =buildings.begin();
    while( itr != buildings.end()) {
        height = *itr;
        while (!sunsetApp.empty() && height >= sunsetApp.top().second ) {
            sunsetApp.pop();
        }
        sunsetApp.emplace(make_pair(index++,height));
        itr++;
    }
    vector<int>retval;
    while (!sunsetApp.empty()) {
        retval.push_back(sunsetApp.top().second);
        sunsetApp.pop();
    }
    return retval;
}
int main() {
    vector<int> test = {1,2,3,7,5,6,4};
    vector<int> ret = func_sunsetview(test);
    for(auto a: ret)
        cout<<a<<endl;
    return 0;
}
