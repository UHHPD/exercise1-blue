#include <fstream>
#include <iostream>
#include <cmath>

int main() {
    // 2a)
    // declaring streams
    std::ifstream fin("datensumme.txt");
    std::ifstream fin_var("datensumme.txt");
    std::ofstream fout_means("mittelwerte.txt");
    std::ofstream fout_vars("varianzen.txt");

    for(int j = 0; j < 26; j++){
         // calculating mean
        int n;
        int sum = 0;
        for(int i = 0; i < 9; i++) {
            fin >> n;
            sum += n;
        }
        double mean = double(sum)/9;
        fout_means << mean << std::endl;
        
        //calculating variance
        double var_sum = 0;
        for(int i = 0; i < 9; i++) {
            fin_var >> n;
            var_sum += (n - mean) * (n - mean);
        }
        double var = var_sum / 9;
        fout_vars << var << std::endl;
    }
    fin_var.close();
    fin.close();
    fout_means.close();
    fout_vars.close();

    // 2b)

    std::ifstream mean_in("mittelwerte.txt");
    std::ifstream var_in("varianzen.txt");

    double sum_of_means = 0;
    double sum_of_vars = 0;
    double m;
    double v;
    for(int j = 0; j < 26; j++){
        mean_in >> m;
        var_in >> v;
        sum_of_means += m;
        sum_of_vars += v;     
    }
    std::cout << "mean: " << sum_of_means/26 << std::endl;
    std::cout << "variance: " << sum_of_vars/26 << std::endl;
    std::cout << "variace with Bessels correction: " << sum_of_vars/25 << std::endl;
}
