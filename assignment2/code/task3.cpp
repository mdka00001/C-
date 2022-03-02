#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//public class for storing each gene as an object
struct Gene
{
    string chr;
    unsigned long long start;
    unsigned long long stop;
    int clus_n=0;
    unsigned long long mid_pos;

//constructor for Gene class
    Gene (string chr_, unsigned long long start_, unsigned long long stop_){
        chr=chr_;
        start=start_;
        stop=stop_;


    }
    ~Gene();


};
//Calculate distance between two gene
unsigned long long distance(unsigned long long a, unsigned long long b){
    unsigned long long v=0;
    if(a >b){
        v=(a-b);
    }
    else if(a < b){
        v=(b-a);

    }
    return v;
}



int main(int argc, const char *argv[])
{
    //input file as a 2d vector
    vector<vector<string>> main_matrix;
    vector<string> k;
    string sa, sb;

    ifstream file;
    char * gene;
    string line;
    file.open(argv[1], ios::in);
    while ( !file.eof() ) {
        getline(file, line, '\n');
        int Length = line.length();
        char * buf = new char[Length];
        strcpy(buf, line.c_str());
        gene = strtok(buf, " ");
        vector <string> temp;
        while ( gene != NULL ) {
            temp.push_back(gene);
            gene = strtok(NULL, " ");
        }



        if ( !temp.empty() ) {
            sb="";
            sa = temp[0];
            k.clear();
            for(int i=0; i<sa.size(); i++){

                if(sa[i]=='\t'){
                    k.push_back(sb);
                    sb="";
                }
                else{
                    sb=sb+sa[i];
                }
            }
            k.push_back(sb);
            main_matrix.push_back(k);




        }
    }
    file.close();



    if (argc>3) {

//checking order of chrs in the input file
        vector<int> chr_str;

        for (int i = 0; i < main_matrix.size(); i++) {


            if (main_matrix[i][0] == "chr1") {

                chr_str.push_back(1);
            } else if (main_matrix[i][0] == "chr2") {

                chr_str.push_back(2);
            } else if (main_matrix[i][0] == "chr3") {

                chr_str.push_back(3);

            } else if (main_matrix[i][0] == "chr4") {

                chr_str.push_back(4);
            } else if (main_matrix[i][0] == "chr5") {

                chr_str.push_back(5);
            } else if (main_matrix[i][0] == "chr6") {

                chr_str.push_back(6);
            } else if (main_matrix[i][0] == "chr7") {

                chr_str.push_back(7);
            } else if (main_matrix[i][0] == "chr8") {

                chr_str.push_back(8);
            } else if (main_matrix[i][0] == "chr9") {

                chr_str.push_back(9);
            } else if (main_matrix[i][0] == "chr10") {

                chr_str.push_back(10);
            } else if (main_matrix[i][0] == "chr11") {

                chr_str.push_back(11);
            } else if (main_matrix[i][0] == "chr12") {

                chr_str.push_back(12);
            } else if (main_matrix[i][0] == "chr13") {

                chr_str.push_back(13);
            } else if (main_matrix[i][0] == "chr14") {

                chr_str.push_back(14);
            } else if (main_matrix[i][0] == "chr15") {

                chr_str.push_back(15);
            } else if (main_matrix[i][0] == "chr16") {

                chr_str.push_back(16);
            } else if (main_matrix[i][0] == "chr17") {

                chr_str.push_back(17);
            } else if (main_matrix[i][0] == "chr18") {

                chr_str.push_back(18);
            } else if (main_matrix[i][0] == "chr19") {

                chr_str.push_back(19);
            } else if (main_matrix[i][0] == "chr20") {

                chr_str.push_back(20);
            } else if (main_matrix[i][0] == "chr21") {

                chr_str.push_back(21);
            } else if (main_matrix[i][0] == "chr22") {

                chr_str.push_back(22);
            } else if (main_matrix[i][0] == "chrX" or main_matrix[i][0] == "chrx") {

                chr_str.push_back(23);
            } else if (main_matrix[i][0] == "chrY" or main_matrix[i][0] == "chry") {

                chr_str.push_back(24);
            } else {
                std::cerr << "Error: Unorganized list_1" << endl;
                exit(1);
            }

        }




        for (int i = 0; i < main_matrix.size() - 1; i++) {
            for (int j = i + 1; j < main_matrix.size(); j++) {
                for (int k = 0; k < chr_str.size()-1; k++) {
                    for (int l = k+1; l < chr_str.size(); l++) {


                            if (chr_str[k] > chr_str[l]) {


                                std::cerr << "Error: Unorganized list_2";
                                exit(1);

                            }



                            //checking order of gene start in input
                        else if (main_matrix[i][0] == main_matrix[j][0]) {
                            long long a = stoull(main_matrix[i][1]);
                            long long b = stoull(main_matrix[j][1]);
                            if (a > b) {

                                std::cerr << "Error: Unorganized list_3" << endl;
                                exit(1);

                            }
                            //checking order of gene stop when start is equal in input
                        } else if (main_matrix[i][0] == main_matrix[j][0]) {
                            long long a = stoull(main_matrix[i][1]);
                            long long b = stoull(main_matrix[j][1]);
                            long long c = stoull(main_matrix[i][2]);
                            long long d = stoull(main_matrix[j][2]);
                            if (a == b and c > d) {

                                std::cerr << "Error: Unorganized list_4" << endl;
                                exit(1);

                            }
                        } else {

                            //creating a vector of class Gene and storing all the input genes
                            vector<unsigned long long> start;
                            vector<unsigned long long> stop;
                            vector<Gene *> chr;
                            for (int i = 0; i < main_matrix.size(); i++) {
                                start.push_back(stoull(main_matrix[i][1]));
                                stop.push_back(stoull(main_matrix[i][2]));
                                Gene *gene = new Gene(main_matrix[i][0], start[i], stop[i]);
                                chr.push_back(gene);
                            }
                            // calculating middle position of each gene
                            for (int i = 0; i < chr.size(); i++) {
                                if (chr[i]->start > chr[i]->stop) {
                                    chr[i]->mid_pos = (chr[i]->start + chr[i]->stop) / 2;
                                } else if (chr[i]->stop > chr[i]->start) {
                                    chr[i]->mid_pos = (chr[i]->stop + chr[i]->start) / 2;
                                }
                            }


                            long long dist = atoi(argv[2]);


                            //assigning cluster to each gene
                            for (int i = 0; i < chr.size(); i++) {
                                chr[i]->clus_n = i + 1;
                            }
                            for (int i = 0; i < chr.size() - 1; i++) {

                                for (int j = i; j < chr.size(); j++) {
                                    if (chr[i]->chr == chr[j]->chr) {
                                        if (distance(chr[i]->mid_pos, chr[j]->mid_pos) <= dist) {
                                            int index = chr[i]->clus_n;
                                            chr[i]->clus_n = index;
                                            chr[j]->clus_n = index;

                                        } else if (distance(chr[i]->mid_pos, chr[j]->mid_pos) > dist) {
                                            int index = chr[i]->clus_n;
                                            index++;
                                            chr[j]->clus_n = index;
                                        }


                                    } else {
                                        int index = chr[i]->clus_n;
                                        index++;
                                        chr[j]->clus_n = index;
                                    }


                                }
                            }
                            //processing output file
                            std::ofstream outfile(argv[3]);
                            for (int k = 0; k < chr.size(); k++) {
                                outfile << chr[k]->chr << '\t' << chr[k]->start << '\t' << chr[k]->stop << '\t'
                                        << "cluster="
                                        << chr[k]->clus_n << endl;
                            }
                            outfile.close();
                        }
                    }

                }
            }

        }
    }
    else{

            std::cerr << "Error: arguments not satisfied"<< endl;
            exit(1);
        }

    return 0;
}

