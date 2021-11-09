#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include<sstream>
using namespace std;
//function to calculate hamming distance//
double humming(string& a, string& b){
    double difference=0;
    double match=0;

    while (a.length() == b.length()){
        for (int i = 0; i<a.length(); i++){
            if (a.at(i)!=b.at(i)){
                difference++;
            }
            else{
                match++;
            }

        }
        return difference;

    }
    return difference;

}

//counting the frequency of kth substring in strings//
double substring(string& a, string& b)
{
    double count = 0;

    if (b.length() == 0)
        return 0;


    for (size_t match = a.find(b); match != string::npos;
         match = a.find(b,  match + 1))
    {
        ++count;

    }

    return count;

}
//function to calculate the minimum maximum mean and median of the hamming distance//
double results(vector<double>& v) {
    sort(v.begin(), v.end());
    double mean;
    double median;
    vector<double> result;

    if (v.empty()) {
        return 0;
    }
    else{
        mean = (accumulate(v.begin(), v.end(), 0.0)) / (v.size());
        median = v.at(v.size() / 2);

    }
    cout << v[0] << " " << v[v.size()-1] << " " << mean << " " << median << " ";
    return 0;

}

int main(int argc, char ** argv) {
    //taking input as space separated strings in vector//
            string sa, sb;


            vector<vector<string>> main_matrix;

            vector<string> k;


            while (getline(cin, sa) && !sa.empty()) {


                sb = "";
                k.clear();
                for (int j = 0; j < sa.size(); j++) {

                    if (sa[j] == ' ') {
                        k.push_back(sb);
                        sb = "";
                    } else {
                        sb = sb + sa[j];
                    }
                }

                k.push_back(sb);
                main_matrix.push_back(k);


            }
            if (argc>1) {

                int agr_val = atoi(argv[1]);


                for (int i = 0; i < main_matrix.size(); i++) {


                    if (main_matrix[i].size() < agr_val) {
                        cout << "" << endl;
                    } else {
                        string arg = argv[2];


                        double occurrence = 0;
                        for (int j = 0; j < (main_matrix[i].size()); j++) {
                            occurrence = occurrence + substring(main_matrix[i][j], arg);

                        }

                        string n_string = main_matrix[i][agr_val - 1];


                        main_matrix[i].erase(main_matrix[i].begin() + (agr_val - 1));

                        vector<double> ham_result;

                        for (int j = 0; j < (main_matrix[i].size()); j++) {
                            double val = humming(n_string, main_matrix[i][j]);

                            ham_result.push_back(val);
                        }

                        results(ham_result);
                        cout << occurrence << endl;
                    }
                }
            }



            return 0;
        }




