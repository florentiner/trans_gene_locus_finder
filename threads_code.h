//
// Created by Данил Ежов on 03.01.2022.
//

#ifndef TRANS_GENE_LOCUS_FINDER_THREADS_CODE_H
#define TRANS_GENE_LOCUS_FINDER_THREADS_CODE_H

#include "iostream"
#include <zlib.h>

std::string reverse(std::string str);
void open_file(std::string name_of_file);
std::vector< char > readline( gzFile f );
void alg_of_read_left(std::string seq, std::string qual);
void alg_of_read_rigt(std::string seq, std::string qual);



inline int unic_nuc = 0;
inline std::string thresd1_find = "";
inline std::string thresd2_find = "";
inline std::string thresd3_find = "";
inline std::string thresd4_find = "";








#endif //TRANS_GENE_LOCUS_FINDER_THREADS_CODE_H
