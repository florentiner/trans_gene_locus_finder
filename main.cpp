#include <iostream>
#include <fstream>
#include "threads_code.h"
#include <fstream>
#include <string>
#include <cmath>
#include <zlib.h>
#include "vector"


std::string execute(const std::string& command) {
    system((command + " > temp.txt").c_str());

    std::ifstream ifs("temp.txt");
    std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
    ifs.close(); // must close the inout stream so the file can be cleaned up
    if (std::remove("temp.txt") != 0) {
        perror("Error deleting temporary file");
    }
    return ret;
}



//int main(int argc, char *argv[])
int main(int argc, char *argv[]) {
    //open_file(argv[1]);
    //alg_of_read_left("GATTTAGTGCTTTACGGCACCTCGACCCCAAAAAACTTGATTAGGGTGATGGTTCACGTAGTGGGCCATCGCCCTGATAGACGGTTTTTCGCCCTTTGACGTAGCGTCGATTTTTGTGATGCTCGTCAGGGGGGCGGAGCCTATGGAAAAA", "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF,FFFF:F,:F,F:::::,::FFFF:FF,:FF,F:,F,FFFF");
    //std::string file = "/Users/danilezov/Desktop/Imun_lab/RCGS_S000001_MS-5/RCGS_S000001_MS-5_L001_R1_001.fastq.gz";
    //open_file(file);


    std::ifstream infile(argv[3]);
    std::string line;
    getline(infile,line);
    std::string vectors_alig = line;
    std::transform(vectors_alig.begin(), vectors_alig.end(),vectors_alig.begin(), ::toupper);



    unic_nuc = atoi(argv[2]);
    thresd1_find = vectors_alig.substr(0,unic_nuc);
    thresd2_find = reverse(thresd1_find);
    thresd3_find = vectors_alig.substr(vectors_alig.length() - unic_nuc,unic_nuc);
    thresd4_find = reverse(thresd3_find);

    open_file(argv[1]);

    return 0;
}
