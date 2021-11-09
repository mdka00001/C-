#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include<sstream>
using namespace std;



int main(int argc, char **argv) {

    vector<vector<string>> main_matrix;
    vector<string> temp;
    if (argc < 2) {
        return 0;
    }

    std::ifstream input(argv[1]);
    if (!input.good()) {
        return 0;
    }
    std::string file, id, sequence;

    while (std::getline(input, file)) {

        if(file.empty())
            continue;

        if (file[0] == '>') {

            if(!id.empty()){
                temp.push_back(sequence);
                main_matrix.push_back(temp);
                temp.clear();}

            id = file.substr(1);
            sequence.clear();

        }
        else {
            sequence += file;
        }
    }

    if(!id.empty()) {
        temp.push_back(sequence);
        main_matrix.push_back(temp);
        temp.clear();
    }



    //Converting RNA to DNA and filtering out non DNA/RNA strings//
    vector<string> unwanted{"B", "D", "E", "F", "H", "I", "J", "K", "L", "M",
                            "N", "O", "P", "Q", "R", "S", "V", "W", "X", "Y",
                            "Z", "b", "d", "e", "f", "h", "i", "j", "k", "l",
                            "m", "n", "o", "p", "q", "r", "s", "v", "w", "x", "y", "z"};

    string U = "U";
    string u = "u";

    string dna;
    size_t pos;
    vector<string> final_seq;

    vector<string> next_string;
    vector<string> next_string_2;


    for (int m = 0; m < main_matrix.size(); m++) {
        for (int n = 0; n < main_matrix[m].size(); n++) {

            string temp = main_matrix[m][n];


            for (int i = 0; i < temp.length(); i++) {
                for (int j = 0; j < unwanted.size(); j++) {
                    for (int l = 0; l < unwanted[i].size(); l++) {
                        if (temp[i] == unwanted[j][l]) {

                            dna = ("");

                        } else if (temp[i] != unwanted[j][l] && temp[i] == 'U') {
                            while ((pos = temp.find(U, i)) != string::npos) {
                                dna = (temp.replace(pos, U.length(), "T"));

                            }
                        } else if (temp[i] != unwanted[j][l] && temp[i] == 'u') {
                            while ((pos = temp.find(u, i)) != string::npos) {
                                dna = (temp.replace(pos, u.length(), "t"));


                            }
                        } else if (temp[i] != unwanted[j][l] && (temp[i] == 'A' ||
                                                                 temp[i] == 'T' || temp[i] == 'G' ||
                                                                 temp[i] == 'C' || temp[i] == 'a'
                                                                 || temp[i] == 't' || temp[i] == 'g' ||
                                                                 temp[i] == 'c')) {
                            dna = (temp);
                        }
                    }
                }
            }
            final_seq.push_back(dna);
        }
    }

    //eliminating empty strings//
    for (int i = 0; i < final_seq.size(); i++) {
        string seq;
        if (final_seq[i] == " ") {
            seq = "";
        }  else {
            seq = final_seq[i];
            next_string.push_back(seq);
        }

    }

    //computing the next larger permutation//
    for (int i = 0; i < next_string.size(); i++) {

        bool val = next_permutation(next_string[i].begin(), next_string[i].end());
        if (val == false){

            continue;
        }
        else {

            next_string_2.push_back(next_string[i]);

        }

    }

    //sorting vector by length//
    sort(next_string_2.begin(), next_string_2.end(), []
            (const string& small, const string& large) {
        return small.size() < large.size();
    });

    //sorting vector lexicographically//
    string tmp;

    for (int i = 0; i < next_string_2.size()-1; i++) {
        for (int j=i+1; j<next_string_2.size(); j++) {
            if (next_string_2[i].length() == next_string_2[j].length()) {
                string one = next_string_2[i];
                string two = next_string_2[j];

                if (lexicographical_compare(two.begin(), two.end(), one.begin(), one.end())) {
                    tmp = next_string_2[i];
                    next_string_2[i] = next_string_2[j];
                    next_string_2[j] = tmp;
                } else {
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < next_string_2.size(); i++) {
        cout << next_string_2[i] << endl;
    }


    return 0;

}