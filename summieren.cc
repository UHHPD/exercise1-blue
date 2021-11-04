#include <fstream>
#include <iostream>

int main() {
    std::ifstream fin("daten.txt");
    std::ofstream fout("datensumme.txt");
    int n1, n2;
    for(int i = 0; i < 234; i++) {
        fin >> n1;
        fin >> n2;
        fout << n1 + n2 << std::endl;
    }
    fin.close();
    fout.close();
}
