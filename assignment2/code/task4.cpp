#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Optimal_NW
{
    vector<vector<int>> matrix;

    Optimal_NW(vector<vector<int>> &a){
        matrix = a;
    }
};

int main(int argc, const char *argv[]){

    if(argc>1){

        string seq1=argv[1];
        string seq2=argv[2];




        //Create matrix
        auto m = seq1.length()+1;
        auto n = seq2.length()+1;
        auto default_value = 0;
        std::vector<std::vector<int>> main_matrix(m, std::vector<int>(n, default_value));

        vector<vector<int>> tracer_matrix;
        vector<int> temp;
        int val;


        //scores for match, mismatch and gap
        int match_reward =1;
        int mismatch_penalty = -1;
        int gap_penalty = -1;

        //Fill match checker matrix
        for(int i=0; i<seq1.length(); i++){
            for(int j=0; j<seq2.length(); j++){
                if (seq1[i]==seq2[j]){
                    val=match_reward;
                    temp.push_back(val);
                }
                else{
                    val=mismatch_penalty;
                    temp.push_back(val);
                }

            }
            tracer_matrix.push_back(temp);
            temp.clear();

        }

        // Fill main matrix using needleman_wunsch algorithm
        for(int i=0; i<seq1.length()+1; i++){
            for(int j=0;j<seq2.length()+1; j++) {
                main_matrix[i][0]=i*gap_penalty;
                main_matrix[0][j]=j*gap_penalty;
            }
        }
        for(int i=1; i<seq1.length()+1; i++){
            for(int j=1;j<seq2.length()+1; j++) {
                main_matrix[i][j] = max({main_matrix[i-1][j-1]+tracer_matrix[i-1][j-1], main_matrix[i-1][j]+gap_penalty, main_matrix[i][j-1]+gap_penalty});

            }
        }



        // backtracking
        string aligned_seq1;
        string aligned_seq2;

        int len_i=seq1.length();
        int len_j=seq2.length();

        while(len_i>0 and len_j>0){
            if(len_i>0 and len_j>0 and main_matrix[len_i][len_j]==main_matrix[len_i-1][len_j-1]+tracer_matrix[len_i-1][len_j-1]){
                aligned_seq1 = seq1[len_i-1]+aligned_seq1;
                aligned_seq2 = seq2[len_j-1]+aligned_seq2;

                len_i = len_i-1;
                len_j = len_j-1;



            }
            else if(len_i>0 and main_matrix[len_i][len_j]==main_matrix[len_i-1][len_j]+gap_penalty){
                aligned_seq1=seq1[len_i-1]+aligned_seq1;
                aligned_seq2="_"+aligned_seq2;
                len_i = len_i-1;



            }
            else {
                aligned_seq1 ="_"+aligned_seq1;
                aligned_seq2 =seq2[len_j-1]+aligned_seq2;

                len_j =len_j-1;


            }
        }

        /*for(int i=0; i<main_matrix.size(); i++) {
            for (int j = 0; j < main_matrix[i].size(); j++) {
                cout << main_matrix[i][j] << " ";
            }
            cout << endl;

        }*/
        cout << main_matrix[seq1.length()][seq2.length()] << endl;
        cout << aligned_seq1 << endl;
        cout << aligned_seq2 << endl;

    }
    return 0;
}
