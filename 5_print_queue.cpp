#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

struct rule
{
    int before;
    int after;
};

void printVector(vector<int> x){
    for (auto i : x){
        cout << i << " ";
    }
    cout << endl;
}

bool validity(vector<int> update, vector<rule> rules){
    bool valid=true;

            for (int i=0; i<update.size(); i++){
                //before check: are there any numbers before this that should really come after it.
                //dont check first num
                if(i!=0){                
                    vector<int> after;
                    for ( auto r : rules){
                        if(r.before==update[i])
                            after.push_back(r.after);
                    }
                    for ( int j=0; j<i; j++){
                        if(find(after.begin(), after.end(), update[j])!=after.end()){
                            valid=false;
                            int change = update[j];
                            update.insert(update.begin()+i-1, change);
                            update.erase(update.begin()+j);
                        }
                    }
                }
                
                //after check: are there any numbers after this that should come before it.
                //dont check last num
                if(i!=update.size()-1){
                    vector<int> before;
                    for ( auto r : rules){
                        if(r.after==update[i])
                            before.push_back(r.before);
                    }
                    for ( int j=i+1; j<update.size(); j++){
                        if(find(before.begin(), before.end(), update[j])!=before.end()){
                            valid=false;
                        }
                    }
                }
            }
    return valid;
}

vector<int> reorder(vector<int> update, vector<rule> rules){
    bool valid=true;
    for (int i=0; i<update.size(); i++){
                //before check: are there any numbers before this that should really come after it.
                //dont check first num
                if(i!=0){                
                    vector<int> after;
                    for ( auto r : rules){
                        if(r.before==update[i])
                            after.push_back(r.after);
                    }
                    for ( int j=0; j<i; j++){
                        if(find(after.begin(), after.end(), update[j])!=after.end()){
                            valid=false;
                            // cout << "After: " << update[i] << " -> ";
                            // printVector(after);
                            cout << update[i] << " before " << update[j] << " -> ";
                            printVector(update);
                            int change = update[j];
                            update.erase(update.begin()+j);
                            update.insert(update.begin()+i+1, change);
                            cout << "After update: ";
                            printVector(update);
                        }
                    }
                }
                
                //after check: are there any numbers after this that should come before it.
                //dont check last num
                if(i!=update.size()-1){
                    vector<int> before;
                    for ( auto r : rules){
                        if(r.after==update[i])
                            before.push_back(r.before);
                    }
                    for ( int j=i+1; j<update.size(); j++){
                        if(find(before.begin(), before.end(), update[j])!=before.end()){
                            valid=false;
                            // cout << "Before: " << update[i] << " -> ";
                            // printVector(before);
                            cout << update[i] << " after " << update[j] << " -> ";
                            printVector(update);
                            int change = update[j];
                            update.erase(update.begin()+j);
                            update.insert(update.begin()+i, change);
                            cout << "After update: ";
                            printVector(update);
                            i++;
                        }
                    }
                }
    }
    return update;
}

int main(){
    ifstream f("5_print_queue.txt");

    string line;
    vector<rule> rules;
    string flag = "rules";
    int sum;

    while (getline(f, line)){
        if (line==""){
            flag = "updates";
            continue;
        }
        if (flag == "rules"){
            rule r;
            r.before = stoi(line.substr(0, line.find("|")));
            r.after = stoi(line.substr(line.find("|")+1, -1));
            rules.push_back(r);
        }
        if (flag == "updates"){
            vector<int> update;

            do{
                update.push_back(stoi(line.substr(0, line.find(","))));
                line = line.substr(line.find(",")+1, -1);
            }while(line.find(",")!=string::npos);
            update.push_back(stoi(line));

            bool valid = validity(update, rules);

            while (!validity(update, rules)){
                update = reorder(update, rules);
            }

            printVector(update);

            if (!valid)
                sum += update[update.size()/2];
        }
        }
        cout << sum << endl;
    }
