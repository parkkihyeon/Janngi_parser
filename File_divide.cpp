#include "File_divide.h"

int start_page = 0 ;
bool braket_ = false ;

char* Fit_Digit(int num_, int cipher)
{
	int original_num_len = to_string(num_).length() ;
	char *Trans_char= new char[MIN] ;
	string Trans_str ;

	// cipher�� ���̸�ŭ ����� ���� �������� 0���� ä���� ��
	for(int i=0 ; i< cipher - original_num_len ;i++)
		Trans_str.push_back('0') ;

	// num_�� �ڿ� ���̸� cipher ���� ��ŭ �����ȴ�.
	Trans_str.append(to_string(num_)) ;
	strcpy(Trans_char,Trans_str.c_str()) ;

	return Trans_char; 
}

void Devide_Doc(int end_txt, char *original_name, int start_txt)
{
	for(int num_for = start_txt ; num_for < end_txt ; num_for++){
		// text �̸� �ֱ�.
		char *name_copy = new char[MIN] ;
		char *File_name = new char[MIN] ;
		char *sentence = new char[MIN];
		int num_of_leftbraket = 0 ;

		// �ۼ��� ���� �̸��� ���Ŀ� �°�.
		strcpy(name_copy, original_name) ;
		strcat(name_copy, Fit_Digit(num_for, to_string(end_txt).length())) ;
		strcat(name_copy, TEXT_GIBO) ;
		cout << name_copy << endl ;

		// ���� ����
		ifstream stream(name_copy) ;
		if(stream.fail()) {
			cerr << "oepn failed " << endl ;
			break ;
		}

		Convert_Filename(File_name) ;

		while (!stream.eof())
		{
			// ������ ���ϵ� 0.txt ���� �����Ѵ�.
			ofstream ostream(File_name);
			int new_line = 0 ;

			while (!stream.eof())
			{
				stream.getline(sentence, MIN);

				// �ּ��� ���۵ưų� �����̸�
				if(sentence[0] == '{' || braket_ == true){
					braket_ = true ;
					// ������ �������� �ּ��� �ݴ°����� Ȯ��.
					if(sentence[strlen(sentence)-1] == '}'){
						braket_ = false ;
					}
					continue ;
				}
				else {
					if (sentence[0] == NULL) new_line++ ;
					if(new_line == 2 ){
						// ������ �����Ѵ�.
						Convert_Filename(File_name) ;
						break ;
					}
					ostream << sentence <<endl ;
				}
			}
			ostream.close() ;
		}
		stream.close() ;
		delete(File_name) ;
		delete(sentence) ;
		delete(name_copy) ;
	}
}

void Convert_Filename(char *str)
{
	// int to char
	strcpy(str, "") ;
	itoa(start_page,str, DECIMAL) ;
	strcat(str, TEXT_FORM) ;
	start_page++;
}
