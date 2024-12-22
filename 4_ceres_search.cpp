#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

void print2dVector(vector<vector<string>> v){
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ifstream f("4_ceres_search.txt");

    string line;
    vector<vector<string>> x;

    int i = 0;
    while (getline(f, line)){
        vector<string> temp;
        for (int j=0; j<line.size(); j++){
            string s;
            temp.push_back(s+line[j]);
        }
        x.push_back(temp);
    }

    print2dVector(x);

    //forward row
    int forward_row=0;
    for (int i = 0; i<x.size(); i++){
        for (int j = 0; j<x[i].size()-3; j++){
            if (x[i][j]+x[i][j+1]+x[i][j+2]+x[i][j+3]=="XMAS"){
                forward_row++;
            }
        }
    }

    //reverse row
    int reverse_row=0;
    for (int i = 0; i<x.size(); i++){
        for (int j = 0; j<x[i].size()-3; j++){
            if (x[i][j]+x[i][j+1]+x[i][j+2]+x[i][j+3]=="SAMX"){
                reverse_row++;
            }
        }
    }

    //forward column
    int forward_column=0;
    for (int i = 0; i<x.size()-3; i++){
        for (int j = 0; j<x[i].size(); j++){
            if (x[i][j]+x[i+1][j]+x[i+2][j]+x[i+3][j]=="XMAS"){
                forward_column++;
            }
        }
    }

    //reverse column
    int reverse_column=0;
    for (int i = 0; i<x.size()-3; i++){
        for (int j = 0; j<x[i].size(); j++){
            if (x[i][j]+x[i+1][j]+x[i+2][j]+x[i+3][j]=="SAMX"){
                reverse_column++;
            }
        }
    }

    //forward diagonal_lr
    int forward_diagonal_lr=0;
    for (int i = 0; i<x.size()-3; i++){
        for (int j = 0; j<x[i].size()-3; j++){
            if (x[i][j]+x[i+1][j+1]+x[i+2][j+2]+x[i+3][j+3]=="XMAS"){
                forward_diagonal_lr++;
            }
        }
    }

    int forward_diagonal_rl=0;
    for (int i = 0; i<x.size()-3; i++){
        for (int j = x[i].size()-1; j>2; j--){
            if (x[i][j]+x[i+1][j-1]+x[i+2][j-2]+x[i+3][j-3]=="XMAS"){
                forward_diagonal_rl++;
            }
        }
    }

    int reverse_diagonal_lr=0;
    for (int i = 0; i<x.size()-3; i++){
        for (int j = 0; j<x[i].size()-3; j++){
            if (x[i][j]+x[i+1][j+1]+x[i+2][j+2]+x[i+3][j+3]=="SAMX"){
                reverse_diagonal_lr++;
            }
        }
    }

    int reverse_diagonal_rl=0;
    for (int i = 0; i<x.size()-3; i++){
        for (int j = x[i].size()-1; j>2; j--){
            if (x[i][j]+x[i+1][j-1]+x[i+2][j-2]+x[i+3][j-3]=="SAMX"){
                reverse_diagonal_rl++;
            }
        }
    }

    int xmas=0;
    for (int i = 0; i<x.size()-2; i++){
        for (int j = 0; j<x[i].size()-2; j++){
            if (x[i][j]+x[i+1][j+1]+x[i+2][j+2]=="MAS" || x[i][j]+x[i+1][j+1]+x[i+2][j+2]=="SAM"){
                if(x[i+2][j]+x[i+1][j+1]+x[i][j+2]=="MAS" || x[i+2][j]+x[i+1][j+1]+x[i][j+2]=="SAM"){
                    xmas++;
                }
            }
        }
    }


    cout << "Forward row: " << forward_row << endl;
    cout << "Reverse row: " << reverse_row << endl;
    cout << "Forward column: " << forward_column << endl;
    cout << "Reverse column: " << reverse_column << endl;
    cout << "Forward diagonal: " << forward_diagonal_lr+forward_diagonal_rl << endl; 
    cout << "Reverse diagonal: " << reverse_diagonal_lr + reverse_diagonal_rl << endl;  
    cout << "Total XMAS: " << forward_column + forward_row + reverse_column + reverse_row + forward_diagonal_lr + forward_diagonal_rl + reverse_diagonal_lr + reverse_diagonal_rl << endl;
    cout << "Total X-MAS: " << xmas << endl;
    return 0;
}
