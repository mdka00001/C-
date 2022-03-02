#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//function to validate all the coverage of beamers/catapults in the landscape//
int beam_count(vector<int>& s){
    int count=0;
    for(int i=0;i<s.size(); i++){
        if(s[i]==1){
            count++;

        }
    }
    return count==s.size();
}

//function to count the number of catapults/beamers in the landscape//

int station_count(const vector<vector<int>> &main_matrix, int coverage, int beam_cat ){
    
//vector for validation//    
    vector<int> beamer(main_matrix[0][0], 1);

    int one_count = 0;
    
    //count number of 1's/2's//
    for(int i=0; i<main_matrix[1].size(); i++){
        if(main_matrix[1][i]==beam_cat){
            one_count++;

        }
    }
    
    
    if(one_count<(main_matrix[1].size()/coverage)-1){
        //cout << "l1" << endl;
        return -1;
    }
    if(one_count==main_matrix[1].size()){
        //cout << "l2" << endl;
        return (main_matrix[1].size()/coverage)-1;
    }
    
    //assignment of coverage of each city by beamer/catapults for given distance//
    if(one_count==(main_matrix[1].size()/coverage)-1){
        for (int j=0; j<main_matrix[1].size(); j++){
            if(main_matrix[1][j]==1){
                for(int k=0; k<=coverage; k++){
                    if(j-k > -1){
                        beamer[j-k]=1;
                    }
                    if(j+k < main_matrix[1].size()){
                        beamer[j+k]=1;
                    }
                }
                beamer[j]=1;
            }
        }
        
        //check if all the city's are covered//
        if(beam_count(beamer)){
            //cout << "l3" << endl;
            return one_count;
        }
        else{
            //cout << "l4" << endl;
            return -1;
        }

    }


    //counting the number of catapults/beamers required//
    int station = 0;
    for (int i; i< main_matrix[1].size(); i++) {


        if (main_matrix[1][i] == 1) {
            for (int j = 1; j < coverage; j++) {
                if (i - j > -1 and !beamer[i - j]) {
                    beamer[i - j] = 1;
                    station++;
                }
                if (i + j < main_matrix[1].size() and !beamer[i + j]) {
                    beamer[i + j] = 1;
                    station++;
                }
            }
        }


    }
    return station;



}
int main(int argc, const char* argv[]) {
    
    //taking input in a 2d vector//
    string sa, sb;


    vector<vector<int>> main_matrix;

    vector<int> k;


    while (getline(cin, sa) && !sa.empty()) {


        sb = "";
        k.clear();
        for (int j = 0; j < sa.size(); j++) {

            if (sa[j] == ' ') {
                k.push_back(stod(sb));
                sb = "";
            } else {
                sb = sb + sa[j];
            }
        }

        k.push_back(stod(sb));
        main_matrix.push_back(k);


    }
    
    //passing values to the functions defined above//
    cout << "beamer:"<<station_count(main_matrix, main_matrix[0][1], 1)<<endl;
    cout << "cata:"<<station_count(main_matrix, main_matrix[0][2], 2)<<endl;


    /*for(int i=0; i<main_matrix[1].size(); i++){
        cout << main_matrix[1][i]<<endl;

    }*/


  return 0;
}
