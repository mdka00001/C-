#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <random>
#include <cmath>
#include <experimental/iterator>
#include <math.h>
using namespace std;

int main(int argc, const char* argv[]) {

    if(argc >5) {

        //taking arguments as variable
        int n = atoi(argv[1]);
        int m = atoi(argv[2]);
        unsigned int s = atoi(argv[3]);
        double p = atof(argv[4]);
        unsigned int k = atoi(argv[5]);

        //Mersenne twister pseudorandom variable generator with seed s

        mt19937_64 generator(s);


        vector<double> v_1;


        //Distributor function
        negative_binomial_distribution<int> distribution(k, p);


        //filing vector v1
        for (int i = 0; i < n; ++i) {
            double counting = distribution(generator);
            v_1.push_back(counting);
        }


        // Printing the sequence stored in an array p



        /*for (auto &i: v_1){
            cout << v_1[i] << endl;
        }*/

        // calculate and print mean
        double average = accumulate(v_1.begin(), v_1.end(), 0.0) / v_1.size();
        cout << "V1 Mean: " << average << endl;

        //calculate and print stdev with presicion = 3

        double accum = 0.0;
        std::for_each(std::begin(v_1), std::end(v_1), [&](const double d) {
            accum += (d - average) * (d - average);
        });

        double stdev = sqrt(accum / (v_1.size() - 1));


        cout << "V1 Sample standard deviation: " << std::setprecision(3) << stdev << endl;

        //log scaling

        vector<double> v_1_scaled = v_1;
        std::for_each(v_1_scaled.begin(), v_1_scaled.end(), [](auto &c) { c = log2(abs(c) + 1); });
        vector<double> v_1_unsorted=v_1_scaled;
        std::sort(v_1_scaled.begin(), v_1_scaled.end(), std::greater<>());
        cout << "V1 Top " << n <<" elements: ";
        std::copy(std::begin(v_1_scaled),
                  std::end(v_1_scaled),
                  std::experimental::make_ostream_joiner(std::cout, ", "));

        cout << endl;
        //v2 vector

        // repeating same steps as above with new constraints

        mt19937_64 generator_2(s * 2);


        vector<double> v_2;


        //Distributor function
        negative_binomial_distribution<int> distribution_2(k, p);


        //filing vector v1
        for (int i = 0; i < m; ++i) {
            double counting = distribution_2(generator_2);
            v_2.push_back(counting);
        }

        // calculate and print mean
        double average_2 = accumulate(v_2.begin(), v_2.end(), 0.0) / v_2.size();

        cout << "V2 Mean: " << std::setprecision(3) <<average_2 << endl;

        //calculate and print stdev with presicion = 3

        double accum_2 = 0.0;
        std::for_each(std::begin(v_2), std::end(v_2), [&](const double d) {
            accum_2 += (d - average_2) * (d - average_2);
        });

        double stdev_2 = sqrt(accum_2 / (v_2.size() - 1));

        //std::cout << std::setprecision(3) << std::fixed;
        cout << "V2 Sample standard deviation: " << std::setprecision(3) <<stdev_2 << endl;

        //log scaling

        vector<double> v_2_scaled = v_2;
        std::for_each(v_2_scaled.begin(), v_2_scaled.end(), [](auto &c) { c = log2(abs(c) + 1); });

        std::sort(v_2_scaled.begin(), v_2_scaled.end(), std::greater<>());
        cout << "V2 Top " << m << " elements: ";

        std::copy(std::begin(v_2_scaled),
                  std::end(v_2_scaled),
                  std::experimental::make_ostream_joiner(std::cout, ", "));


        cout << endl;
        cout << endl;
        cout << "Comparing V1 and V2..." << endl;

        //t-test on unscaled data

        //degree of freedom
        double dof = (v_1.size() + v_2.size() - 2);

        // Pooled variance:

        double sp = sqrt(((v_1.size()-1) * stdev * stdev + (v_2.size()-1) * stdev_2 * stdev_2) / dof);

        // t-statistic:
        double t_stat = (average - average_2) / (sp * sqrt(1.0 / v_1.size() + 1.0 / v_2.size()));



        cout << "Unscaled t-statistic: " << std::setprecision(3) <<t_stat << endl;

        //t-test on scaled data
        //calculate mean for scaled data

        //V1 scaled
        double average_scaled = accumulate(v_1_scaled.begin(), v_1_scaled.end(), 0.0) / v_1_scaled.size();
        //V2 scaled
        double average_2_scaled = accumulate(v_2_scaled.begin(), v_2_scaled.end(), 0.0) / v_2_scaled.size();
        //calculate standard deviation for scaled data

        //V1 scaled
        double accum_scaled = 0.0;
        std::for_each(std::begin(v_1_scaled), std::end(v_1_scaled), [&](const double d) {
            accum_scaled += (d - average_scaled) * (d - average_scaled);
        });
        double stdev_scaled = sqrt(accum_scaled / (v_1_scaled.size() - 1));

        //V2 scaled
        double accum_2_scaled = 0.0;
        std::for_each(std::begin(v_2_scaled), std::end(v_2_scaled), [&](const double d) {
            accum_2_scaled += (d - average_2_scaled) * (d - average_2_scaled);
        });
        double stdev_2_scaled = sqrt(accum_2_scaled / (v_2_scaled.size() - 1));
        // Pooled variance:

        double sp_log = sqrt(((v_1_scaled.size()-1) * stdev_scaled * stdev_scaled + (v_2_scaled.size()-1) * stdev_2_scaled * stdev_2_scaled) / dof);

        // t-statistic:
        double t_stat_log = (average_scaled - average_2_scaled) / (sp_log * sqrt(1.0 / v_1_scaled.size() + 1.0 / v_2_scaled.size()));

        cout << "Scaled t-statistic: " << std::setprecision(3) <<t_stat_log << endl;



        cout << "Total degrees of freedom: " << dof << endl;


        //random number generator

        random_device rand;
        mt19937_64 generator_3(s*7);
        uniform_int_distribution <> distributor_3(1,n);

        //generate vector v3 with numbers ranging 1 to n
        vector<double> v_3;

        for(double i=1; i<n+1; i++){
            v_3.push_back(i);
        }

        //shuffling the numbers with MT algorithm and s*7 seed
        std::shuffle(std::begin(v_3), std::end(v_3), generator_3);



        for(double i=0; i<v_3.size(); i++){
            v_3[i]= v_3[i]*v_1_unsorted[i];

        }

        //sorting even and odd nearest numbers by using two separate vectors
        vector<double> even;
        vector<double> odd;

        vector<double> v_3_sorted;

        for (int i=0; i<v_3.size(); i++){
            int number=((round(v_3[i])*0.5f)*2);
            if(number % 2==0) {
                even.push_back(v_3[i]);
            }
            else{
                odd.push_back(v_3[i]);

            }
        }
        sort(even.begin(), even.end(), greater<double>());
        sort(odd.begin(), odd.end());
        even.insert(even.end(),odd.begin(), odd.end());

        cout << endl;

        cout << "Sorted vector: ";
        std::copy(std::begin(even),
                  std::end(even),
                  std::experimental::make_ostream_joiner(std::cout, ", "));

    }
    else{
        cerr << "Invalid Argument" << endl;
        return 1;
    }

  return 0;
}
