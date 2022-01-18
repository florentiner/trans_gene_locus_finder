//
// Created by Данил Ежов on 03.01.2022.
//

#include "threads_code.h"
#include "iostream"
#include <thread>
#include <fstream>
#include <string>
#include <cmath>
#include <zlib.h>
#include "vector"

void print(std::string to_print){
    std::cout << to_print << std::endl;
}

std::vector< char > readline( gzFile f ) {
    std::vector< char > v( 256 );
    unsigned pos = 0;
    for ( ;; ) {
        if ( gzgets( f, &v[ pos ], v.size() - pos ) == 0 ) {
            // end-of-file or error
            int err;
            const char *msg = gzerror( f, &err );
            if ( err != Z_OK ) {
                std::cout << "Error" << std::endl;
            }
            break;
        }
        unsigned read = strlen( &v[ pos ] );
        if ( v[ pos + read - 1 ] == '\n' ) {
            if ( pos + read >= 2 && v[ pos + read - 2 ] == '\r' ) {
                pos = pos + read - 2;
            } else {
                pos = pos + read - 1;
            }
            break;
        }
        if ( read == 0 || pos + read < v.size() - 1 ) {
            pos = read + pos;
            break;
        }
        pos = v.size() - 1;

        v.resize( v.size() * 2 );
    }
    v.resize( pos );
    return v;
}


void alg_of_read_left(std::string seq, std::string qual){
    for (int i = unic_nuc; i < seq.length()-unic_nuc; ++i) {
        float er = 0;
        bool flag = true;
        for (int j = 0; j < thresd1_find.length(); ++j) {
            if ((er > 4) || (i+j > seq.length()-1)){
                flag = false;
                break;
            }
            else if (seq[i+j] != thresd1_find[j]){
                er += pow(10, (int(qual[i+j]) - 33)/100);
            }
            else if (i+j+1 == seq.length()) {
                break;
            }
        }
        if (flag) {
            std::cout << seq << std::endl;
            std::cout << "find_left" << std::endl;
            break;
        }
    }
}

void alg_of_read_left_rev(std::string seq, std::string qual){
    for (int i = unic_nuc; i < seq.length()-unic_nuc; ++i) {
        float er = 0;
        bool flag = true;
        for (int j = 0; j < thresd2_find.length(); ++j) {
            if ((er > 4) || (i+j > seq.length()-1)){
                flag = false;
                break;
            }
            else if (seq[i+j] != thresd2_find[j]){
                er += pow(10, (int(qual[i+j]) - 33)/100);
            }
            else if (i+j+1 == seq.length()) {
                break;
            }
        }
        if (flag) {
            std::cout << seq.substr (0,i) << std::endl;
            std::cout << "find_left_rev" << std::endl;
            break;
        }
    }
}


void alg_of_read_rigt(std::string seq, std::string qual){
    for (int i = 0; i < seq.length()-2*unic_nuc; ++i) {
        float er = 0;
        bool flag = true;
        for (int j = 0; j < thresd3_find.length(); ++j) {
            if ((er > 4) || (i+j > seq.length()-1)){
                flag = false;
                break;
            }
            else if (seq[i+j] != thresd3_find[j]){
                er += pow(10, (int(qual[i+j]) - 33)/100);
            }
            else if (i+j+1 == seq.length()) {
                break;
            }
        }
        if (flag) {
            std::cout << seq.substr (i,seq.length() - i) << std::endl;
            std::cout << "find_right" << std::endl;
            break;
        }
    }
}

void alg_of_read_rigt_rev(std::string seq, std::string qual){
    for (int i = 0; i < seq.length()-2*unic_nuc; ++i) {
        float er = 0;
        bool flag = true;
        for (int j = 0; j < thresd4_find.length(); ++j) {
            if ((er > 4) || (i+j > seq.length()-1)){
                flag = false;
                break;
            }
            else if (seq[i+j] != thresd4_find[j]){
                er += pow(10, (int(qual[i+j]) - 33)/100);
            }
            else if (i+j+1 == seq.length()) {
                break;
            }
        }
        if (flag) {
            std::cout << seq.substr (i,seq.length() - i) << std::endl;
            std::cout << "find_right_rev" << std::endl;
            break;
        }
    }
}

void threds(std::string seq, std::string qual){
    std::thread tRigtStraight(alg_of_read_rigt, seq, qual);
    std::thread tRigtReverse(alg_of_read_rigt_rev, seq, qual);
    std::thread tLeftStraight(alg_of_read_left, seq, qual);
    std::thread tLeftReverse(alg_of_read_left_rev, seq, qual);
    tRigtStraight.join();
    tRigtReverse.join();
    tLeftStraight.join();
    tLeftReverse.join();
}



void open_file(std::string name_of_file){
    int how_per = 1;
    int gh = 0;
    int gh_t = 0;
    std::string seq;
    std::string qualit;
    float step = 11364979;
    float five_perc = step;

    gzFile fp_ = gzopen(name_of_file.c_str(), "r");

    std::vector< char > line_vect = readline(fp_);

    while (!line_vect.empty())
        {
            std::string line(line_vect.begin(), line_vect.end());
            gh_t++;
            gh++;
            if (gh == 2){
                seq = line;
            }
            if (gh == 4){
                qualit = line;
                threds(seq, qualit);
                gh_t++;
                if (gh_t >= five_perc){
                    //std::cout << how_per * 5 << ' %' << std::endl;
                    five_perc += step;
                    how_per++;
                }
                gh = 0;
            }
            line_vect = readline(fp_);
        }
    gzclose(fp_);
}


//TODO make reverse automatically and find fastest way for global variables
std::string reverse(std::string str){
    std::string ans = "";
    for (int i = str.length()-1; i > -1; --i) {
        ans += str[i];
    }
   return ans;
}

