#include <iostream>
#include <map>
#include <string>
#include <array>
using namespace std;

map<char,int> typemap;

int main()
{

    string s = "IAII*IPP$XVXLAa";
    map<char,int> :: iterator iter;
    int typecount = 0;
    int index;
    char typecollect[10000];
    for(int i = 0; i < s.size(); i++){
        iter = typemap.find(s[i]);
        if(iter == typemap.end()){
            typemap[s[i]] = typecount;
            typecollect[typecount] = s[i];
            typecount ++;
        }
    }
    
    /*
    for(map<char,int> :: iterator iter = typemap.begin(); iter != typemap.end(); iter++){
        cout << iter->first << iter->second << endl;
    }
    */
    
    int collection[typecount][100001];
    
    for(int i = 0; i < s.size(); i++){
        iter = typemap.find(s[i]);
        index = iter->second;
        int nowat = ++collection[index][0];
        collection[index][nowat] = i;
    }

    // traverse by the sequence in map (in this problem, the ASCII sequence)
    for(map<char,int> :: iterator iter = typemap.begin(); iter != typemap.end(); iter++){
        int a = iter->second;
        cout << iter->first << " ";
        for(int i = 1; i <= collection[a][0]; i++){
            cout << collection[a][i] << " ";
        }
        cout << endl;
    }
    
    cout << "---------------------------------------------------------------" << endl;
    
    //traverse by the sequence in string (first time the char appears)
    for(int i = 0; i < typecount; i++){
        iter = typemap.find(typecollect[i]);
        int b = iter->second;
        cout << iter->first << " ";
        for(int i = 1; i <= collection[b][0]; i++){
            cout << collection[b][i] << " ";
        }
        cout << endl;
    }
    
}

