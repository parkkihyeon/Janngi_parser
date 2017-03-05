// 파일 분할
#ifndef _FILE_DIVIDE_H_
#define _FILE_DIVIDE_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

#define TEXT_FORM ".txt"
#define TEXT_GIBO ".gib"
#define DECIMAL 10
#define MIN 200

using namespace std;

void Devide_Doc(int end_txt, char *name, int start_txt) ; // document를 나누기 위한 함수
void Convert_Filename(char *str) ; // Devide_Doc함수에서 파일이름 바꿀때.
char* Fit_Digit(int num_, int cipher) ;

#endif
