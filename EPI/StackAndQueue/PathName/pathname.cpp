#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

int funcNormalizePathNames(const string& path){

    if(path.empty())
        return 0;

    vector<string> mystack;
    if(path.front() == '/'){
          mystack.emplace_back("/");
    }

    std::stringstream ss(path);
    string token;

    while (getline( ss, token , '/')) {
      if(token != "." && token != ".." && token!="")
      {
          mystack.emplace_back(token);
      }
      else if( token == "..")
      {
           if(!mystack.empty()&&  string("/") != mystack.back() )
               mystack.pop_back();
      }
    }

    string retval("");
    int i=0;
     for (i; i < mystack.size();i++)
     {
           retval += mystack[i];
     }
     cout << retval;
}

int main()
{
    string inputstring("./scripts/awkscripts/.././");
    funcNormalizePathNames(inputstring);

}
