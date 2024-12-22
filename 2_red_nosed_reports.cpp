#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

bool problem_dampener(vector<int> line){
    for (int j=0; j<line.size(); j++){
        bool safe=true;
        vector<int> v;
        copy(line.begin(), line.end(), back_inserter(v));
        v.erase(v.begin()+j);

        // for (auto i : v)
        //     cout << i << " ";
        // cout << endl;

        int i = 0;
        if (v[1]>v[0]){
            while (i<v.size()-1){
                if (v[i+1]-v[i]>3 || v[i+1]<=v[i]){
                    safe = false;
                    break;
                }
                i++;
            }
            if (safe==true){
                return true;
            }
        }
        else{
            while (i<v.size()-1){
                if (v[i]-v[i+1]>3 || v[i]<=v[i+1]){
                    safe = false;
                    break;
                }
                i++;
            }
            if (safe==true){
                return true;
            }
    }
    }
    return false;
}

vector<int> get_vector(string line){
    int idx = 0;
    vector<int> out;

    do{
        idx = line.find(" ");
        // cout << "idx: " << idx << endl;
        out.push_back(stoi(line.substr(0, idx)));
        // cout << line.substr(0, idx) << endl;
        line = line.substr(idx+1);
    }while (idx != string::npos);

    // out.push_back(stoi(line));
    // cout << line << endl;

    for (auto i : out)
        cout << i << " ";
    cout << endl;
    return out;
}

int main() {
    ifstream f("2_red_nosed_reports.txt");

    string line;
    bool safe=true;
    vector<int> v;
    int num_safe=0;
    int num_dampener_safe = 0;
    vector<bool> s;
    int line_num = 1;

    while (getline(f, line)){
        v = get_vector(line);
        int i = 0;
        safe = true;

        if (v[1]>v[0]){
            while (i<v.size()-1){
                if (v[i+1]-v[i]>3 || v[i+1]<=v[i]){
                    safe = false;
                    break;
                }
                i++;
            }
            if (safe==true){
                num_safe++;
                s.push_back(1);
            }
            else {
                s.push_back(0);
                if (problem_dampener(v))
                    num_dampener_safe++;
            }

        }
        else{
            while (i<v.size()-1){
                if (v[i]-v[i+1]>3 || v[i]<=v[i+1]){
                    safe = false;
                    break;
                }
                i++;
            }
            if (safe==true){
                num_safe++;
                s.push_back(1);
            }
            else{
                s.push_back(0);
                if (problem_dampener(v))
                    num_dampener_safe++;
            };
            }

        line_num++;
    }

    f.close();
    cout << num_safe << endl;
    cout << num_dampener_safe << endl;
    cout << num_dampener_safe + num_safe << endl;

    // for (auto i : s)
    //     cout << i << " ";

}
