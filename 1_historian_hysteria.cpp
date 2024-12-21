#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

struct lists
{
    vector<int> first;
    vector<int> second;
};

//function to parse the txt file and get two lists
lists parse_txt() {
    vector<int> a;
    vector<int> b;

    ifstream f("historian_hysteria_input.txt");

    string line;
    
    while(getline(f, line)){
        int idx = line.find("   "); 
        a.push_back(stoi(line.substr(0, idx)));
        b.push_back(stoi(line.substr(idx+3)));
    }

    f.close();

    lists out;
    out.first = a;
    out.second = b;
    return out;

}

int main() {
    vector<int> a;
    vector<int> b;

    lists out = parse_txt();

    a = out.first;
    b = out.second;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (!a.size()==b.size()) {
        cerr << "Somehting wrong!";
    }

    int sum = 0;
    int counter = 0;

    do{
        sum = sum + abs(a[counter]-b[counter]);
        counter ++;
    }while(counter<a.size());

    cout << "Total Distance between lists: " << sum << endl;

    int similarity = 0;

    for (int i=0; i<a.size(); i++){
        for (int j = 0; j<b.size(); j++){
            if (b[j]==a[i]){    
                similarity = similarity + b[j];
            } 
        }
    }

    cout << "Similarity: " << similarity << endl;

    return 0;
}
