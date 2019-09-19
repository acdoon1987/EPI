#include <iostream>
#include <stack>
#include <string>
using namespace std;

int funcNormalizePathNames(string str){

    string::iterator itr ;
    for(itr = str.begin(); itr != str.end() ; itr++){
        if(*itr == "/"){
            cout<<*(itr+1);
        }

    }

}

int main()
{
   string inputstring("//./../scripts/awkscripts/././");
   funcNormalizePathNames(inputstring);

}
