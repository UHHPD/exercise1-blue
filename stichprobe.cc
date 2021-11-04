#include <fstream>
#include <iostream>
#include <cmath>

int main() {
    // calculating mean
    std::ifstream fin("datensumme.txt");
    int n;
    int sum = 0;
    for(int i = 0; i < 234; i++) {
        fin >> n;
        sum += n;
    }
    fin.close();
    double mean = double(sum)/234;
    std::cout << "mean: " << mean << std::endl;

    //calculating variance
    std::ifstream fin_var("datensumme.txt");
    double var_sum = 0;
    for(int i = 0; i < 234; i++) {
        fin_var >> n;
        var_sum += (n - mean) * (n - mean);
    }
    fin_var.close();
    double var = var_sum / 234;
    std::cout << "variance: " << var << std::endl;
    double std_dev = sqrt(var);
    std::cout << "standard deviation: " << std_dev << std::endl;
}
