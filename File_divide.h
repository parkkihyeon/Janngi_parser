// ���� ����
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

void Devide_Doc(int end_txt, char *name, int start_txt) ; // document�� ������ ���� �Լ�
void Convert_Filename(char *str) ; // Devide_Doc�Լ����� �����̸� �ٲܶ�.
char* Fit_Digit(int num_, int cipher) ;

#endif
