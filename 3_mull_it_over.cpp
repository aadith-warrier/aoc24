#include <string>
#include <bits/stdc++.h>
#include <regex>

using namespace std; 

int compute(smatch match){
    int first;
    int second;
    int id1 = 4;
    int id2, id3;
    string x;
    
    for (auto i : match)
        x = i;

    id2 = x.find(",");
    id3 = x.find(")");

    first = stoi(x.substr(id1, id2-id1));
    second = stoi(x.substr(id2+1, id3-id2-1));

    return first*second;
}


int main(){
    ifstream f("3_mull_it_over.txt");
    int product=0;
    string line;
    regex pattern("mul\\(\\d+,\\d+\\)");

    while (getline(f, line)){
        smatch match;
        string line2;
        bool enable=true;

        while (regex_search(line, match, pattern)){
            regex_search(line, match, pattern);
            line2 = match.prefix();
            for (int i = 0; i<line2.size(); i++){
                if (line2.substr(i, 4)=="do()"){
                    enable = true;
                }
                if (line2.substr(i, 7)=="don't()"){
                    enable = false;
                }
            }
            if (enable){
                product += compute(match);
            }
            line = match.suffix();
        }
    }

    f.close();
    cout << product << endl;
    return 0;
}
