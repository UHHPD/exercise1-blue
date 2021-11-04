#include <fstream>
#include <iostream>
#include <cmath>

int main() {
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
}
