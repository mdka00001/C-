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
            if (a.at(i)==b.at(i)){
                match++;
            }
            if (a.at(i) != b.at(i)){
                difference++;
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
//function to make a vector of diagonal elements of a matrix//
vector<string> diagonal_matrix(vector<vector<string>>& k ){
    vector<string> matrix;
    for(int i=0;i<k.size();++i) {
        for (int j = 0; j < k[i].size(); ++j) {
            if (i == j)
                matrix.push_back(k[i][j]);

        }

    }
    return matrix;
}

//calculation of minimum maximum mean median hamming distance and occurrence of kth substring in a 2d matrix//
double calculation(int agr_val, string arg, vector<vector<string>> &main_matrix ){
    //calculation on main matrix//
    for (int i = 0; i < main_matrix.size(); i++) {

        //to check if the user input satisfies the first argument. Otherwise it prints an empty line//
        if (main_matrix[i].size() < agr_val) {
            cout << "" << endl;
        } else {
            //taking the 3rd arguement//


            //calculating the frequency of kth substring//
            double occurrence = 0;
            for (int j = 0; j < (main_matrix[i].size()); j++) {
                occurrence = occurrence + substring(main_matrix[i][j], arg);

            }

            string n_string = main_matrix[i][agr_val - 1];

            //remove nth string from the vector of strings//
            main_matrix[i].erase(main_matrix[i].begin() + (agr_val - 1));

            vector<double> ham_result;

            //calculating hamming distance and pushing into ham_result vector//
            for (int j = 0; j < (main_matrix[i].size()); j++) {
                double val = humming(n_string, main_matrix[i][j]);

                ham_result.push_back(val);
            }

            results(ham_result);
            cout << occurrence << endl;
        }
    }

}

//construction of transposed matrix//
vector<vector<string>> trans_matrix(vector<vector<string>>& main_matrix) {
    int i = main_matrix.size();
    if (i == 0) return {{}};
    int j = main_matrix[0].size();
    vector<vector<string>> trans(j, vector<string>(i));
    for (int m = 0; m < i; ++ m) {
        for (int n = 0; n < j; ++ n) {
            trans[n][m] = main_matrix[m][n];
        }
    }
    return trans;
}
//function to take the strings of upper right triangle of a matrix//
vector<string> upper_triangle(vector<vector<string>> &main_matrix)
{
    vector<string> triangle;

    for (int i = 0; i < main_matrix.size(); i++) {
        for (int j = 0; j < main_matrix[i].size(); j++) {
            if (i < j || i==j) {


                triangle.push_back(main_matrix[i][j]);

            }


        }
    }
    return triangle;
}

int main(int argc, char ** argv) {
//taking input as space separated strings in vector//
    string sa, sb;


    vector<vector<string>> main_matrix;

    vector<string> k;

    //reading input into a 2d Matrix
    while (getline(cin, sa, '\n') ) {
        if (sa == ""){

            break;

        }

        sb = "";
        k.clear();
        for (int j = 0; j < sa.size(); j++) {

            if (sa[j] == ' ') {
                k.push_back(sb);
                sb = "";
            } else {
                sb =  sb+sa[j];
            }
        }

        k.push_back(sb);
        main_matrix.push_back(k);



    }
    //constructing diagonal matrix//
    vector<string> d_matrix = diagonal_matrix(main_matrix);
    //constructing upeer triangle vector//
    vector<string > triangle= upper_triangle(main_matrix);

    //constructing transposed matrix//
    vector<vector<string>> trans= trans_matrix(main_matrix);


    if (argc>1) {

        string n_string = argv[2];
        int agr_val = atoi(argv[1]);

        calculation(agr_val, n_string, main_matrix);
        calculation(agr_val, n_string, trans);

        //diagonal matrix//
        if(d_matrix.size()<agr_val){
            cout << "" << endl;
        }
        else {
            double occurrence = 0;
            for (int j = 0; j < (d_matrix.size()); j++) {
                occurrence = occurrence + substring(d_matrix[j], n_string);

            }
            string n_string_diag = d_matrix[agr_val - 1];

            //remove nth string from the vector of strings//
            d_matrix.erase(d_matrix.begin() + (agr_val - 1));

            vector<double> ham_diagonal;

            for (int i = 0; i < d_matrix.size(); i++) {
                double val = humming(n_string_diag, d_matrix[i]);


                ham_diagonal.push_back(val);
            }

            results(ham_diagonal);
            cout << occurrence << endl;
        }

        //upper triangle//
        if(triangle.size()<agr_val){
            cout << "" << endl;}
        else {
            double occurrence_t = 0;
            for (int j = 0; j < (triangle.size()); j++) {
                occurrence_t = occurrence_t + substring(triangle[j], n_string);

            }
            string n_string_tri = triangle[agr_val - 1];

            //remove nth string from the vector of strings//
            triangle.erase(triangle.begin() + (agr_val - 1));

            vector<double> ham_triangle;

            for (int i = 0; i < triangle.size(); i++) {
                double val = humming(n_string_tri, triangle[i]);


                ham_triangle.push_back(val);
            }

            results(ham_triangle);
            cout << occurrence_t << endl;
        }




    }

    return 0;
}