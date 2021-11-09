#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include<sstream>
using namespace std;


using namespace std;

//calculate sum of the inputs
double sum(vector<double> &main_matrix){
    double val;
    for (unsigned i=0; i<main_matrix.size(); i++){
        val +=main_matrix[i];

    }
    return val;
}

//calculate sum of the sum digits
double digit_sum(double val){
    double dig_sum=0;
    double temp;
    int m=val*10;

    while(m>0){

        temp=m%10;
        dig_sum=dig_sum+temp;
        m=m/10;

    }
    return dig_sum;

}
//calculate the nth smallest value
double second_small_val(vector<double> &main_matrix, int arg_1){
    double val;
    sort(main_matrix.begin(),main_matrix.end());
    for (int i=0; i<main_matrix.size(); i++){
        val=main_matrix[arg_1-1];
    }
    return val;
}

//calculate the mth largest value//
double second_large_val(vector<double> &main_matrix, int arg_2){
    double val=0;

    string val2 = "Im";
    reverse(main_matrix.begin(),main_matrix.end());
    for (int i=0; i<main_matrix.size(); i++){
        val=main_matrix[arg_2-1];
    }

    return val;


}

//function to calculate the 3rd quartile//
double quartile(vector<double>& main_matrix) {
    vector<double> v=main_matrix;
    sort(v.begin(), v.end());
    double median;
    double quartile;
    double temp;



    if (v.size()<2) {
        quartile = 0;
    }
    else {
        median = v.at(v.size() / 2);

        if(v.size()%2==0){
            size_t const half = v.size() / 2;
            vector<double> break_bottom(v.begin(), v.begin() + half);
            vector<double> break_top(v.begin() + half, v.end());

            quartile = (accumulate(break_top.begin(), break_top.end(), 0.0)) / (break_top.size());
            v.clear();

        }
        else if(v.size()%2!=0) {
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == median) {
                    temp=median;
                    v.erase(v.begin()+i);
                    size_t const half = v.size() / 2;
                    vector<double> break_bottom(v.begin(), v.begin() + half);
                    vector<double> break_top(v.begin() + half, v.end());

                    quartile = (accumulate(break_top.begin(), break_top.end(), 0.0)) / (break_top.size());
                    v.push_back(temp);
                    v.clear();
                }
            }
        }
    }
    return quartile;

}
//calculate the kaprekar number//
bool kaprekar(double main_matrix) {

    //Reference: https://www.codespeedy.com/kaprekar-number-in-cpp/ //
    string dig = to_string(main_matrix);
    for (int i = 0; i < dig.length(); i++) {
        if (dig[i] == '.') {
            return false;
        } else {


            if (main_matrix == 1) {
                return true;
            } else {
                unsigned int squared = main_matrix * main_matrix;
                int count = 0;
                while (squared) {
                    count++;
                    squared /= 10;
                }
                squared = main_matrix * main_matrix;

                for (int j = 1; j < count; j++) {
                    unsigned int split = pow(10, j);

                    if (split == main_matrix) {
                        continue;

                    }

                    int sum = squared / split + squared % split;
                    if (sum == main_matrix) {
                        return true;
                    }

                }
                return false;
            }
        }
    }
}

//function to reverse a number//
unsigned long long int reverese_num(unsigned long long int val){
    long reversed=0, remainder;
    while(val != 0) {
        remainder = val%10;
        reversed = reversed*10 + remainder;
        val /= 10;
    }
    return reversed;
}

//get the lychrel number//
bool lych(unsigned long long int val, long iter){



    long max=100;
    if(iter>max){
        return true;

    }
    else {

        val = val + reverese_num(val);
        if (val != reverese_num(val)) {
            iter++;
            return lych(val, iter);
        } else {
            return false;
        }

    }


}

int main(int argc, char** argv) {

//taking input as a 2d vector of string
    string sa, sb;


    vector<vector<string>> main_matrix_str;

    vector<string> k;

    //reading input into a 2d Matrix
    while (getline(cin, sa, '\n')) {
        if (sa == "") {

            break;

        }

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
        main_matrix_str.push_back(k);


    }
//strings from main_matrix_str string vector converted to double and inserted in main_matrix vector//
    vector<vector<double>> main_matrix;

    for (int i = 0; i < main_matrix_str.size(); i++) {
        vector<double> temp;
        for (int j = 0; j < main_matrix_str[i].size(); j++) {
            double num = stod(main_matrix_str[i][j]);
            temp.push_back(num);

        }
        main_matrix.push_back(temp);
    }


    if (argc > 1) {
        //taking program arguements in a variable//
        int arg_1 = atoi(argv[1]);
        int arg_2 = atoi(argv[2]);
        //calculating sum, digit sum, 3rd quartile, nth smallest and mth largest number for each row of the //
        //2d vector//
        for (int i = 0; i < main_matrix.size(); i++) {
            double s = sum(main_matrix[i]);
            double ds = digit_sum(s);
            double qs = quartile(main_matrix[i]);
            double ss = second_small_val(main_matrix[i], arg_1);
            double ls = second_large_val(main_matrix[i], arg_2);

            //taking output from above calculation in a new 1d vector//
            vector<double> temp;
            temp.push_back(s);
            temp.push_back(ds),
                    temp.push_back(qs),
                    temp.push_back(ss);
            temp.push_back(ls);

            //printing the output accordingly//
            if (temp[2] == 0 && temp[3] != 0 && temp[4] != 0) {
                cout << s << " " << ds << " " << "Iq" << " " << ss << " " << ls << endl;
            } else if (temp[2] != 0 && temp[3] == 0 && temp[4] != 0) {
                cout << s << " " << ds << " " << qs << " " << "In" << " " << ls << endl;
            } else if (temp[2] != 0 && temp[3] != 0 && temp[4] == 0) {
                cout << s << " " << ds << " " << qs << " " << ss << " " << "Im" << endl;
            } else if (temp[2] != 0 && temp[3] == 0 && temp[4] == 0) {
                cout << s << " " << ds << " " << qs << " " << "In" << " " << "Im" << endl;
            } else if (temp[2] == 0 && temp[3] != 0 && temp[4] == 0) {
                cout << s << " " << ds << " " << "Iq" << " " << ss << " " << "Im" << endl;
            } else if (temp[2] == 0 && temp[3] == 0 && temp[4] != 0) {
                cout << s << " " << ds << " " << "Iq" << " " << "In" << " " << ls << endl;
            } else if (temp[2] == 0 && temp[3] == 0 && temp[4] == 0) {
                cout << s << " " << ds << " " << "Iq" << " " << "In" << " " << "Im" << endl;
            } else {
                cout << s << " " << ds << " " << qs << " " << ss << " " << ls << endl;
            }


        }


    }

    //finding kaprekar and lychrel number//
    vector<int> kap_num;
    vector<unsigned long long int> lych_num;
    for (int i = 0; i < main_matrix.size(); i++) {
        for (int j = 0; j < main_matrix[i].size(); j++) {
            if (kaprekar(main_matrix[i][j])) {
                kap_num.push_back(main_matrix[i][j]);
            }
            if (lych(main_matrix[i][j], 1)) {
                lych_num.push_back(main_matrix[i][j]);
            }


        }
    }
    for (int i = 0; i < kap_num.size(); i++) {
        if (i == kap_num.size() - 1) {
            cout << kap_num[i];
        } else {
            cout << kap_num[i] << " ";
        }


    }
    cout << endl;
    for (int i = 0; i < lych_num.size(); i++) {
        if (i == lych_num.size() - 1) {
            cout << lych_num[i];
        } else {
            cout << lych_num[i] << " ";
        }
    }
}