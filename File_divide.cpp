#include "File_divide.h"

int start_page = 0 ;
bool braket_ = false ;

char* Fit_Digit(int num_, int cipher)
{
	int original_num_len = to_string(num_).length() ;
	char *Trans_char= new char[MIN] ;
	string Trans_str ;

	// cipher의 길이만큼 만들기 위해 나머지를 0으로 채워준 후
	for(int i=0 ; i< cipher - original_num_len ;i++)
		Trans_str.push_back('0') ;

	// num_을 뒤에 붙이면 cipher 길이 만큼 고정된다.
	Trans_str.append(to_string(num_)) ;
	strcpy(Trans_char,Trans_str.c_str()) ;

	return Trans_char; 
}

void Devide_Doc(int end_txt, char *original_name, int start_txt)
{
	for(int num_for = start_txt ; num_for < end_txt ; num_for++){
		// text 이름 넣기.
		char *name_copy = new char[MIN] ;
		char *File_name = new char[MIN] ;
		char *sentence = new char[MIN];
		int num_of_leftbraket = 0 ;

		// 작성한 파일 이름을 형식에 맞게.
		strcpy(name_copy, original_name) ;
		strcat(name_copy, Fit_Digit(num_for, to_string(end_txt).length())) ;
		strcat(name_copy, TEXT_GIBO) ;
		cout << name_copy << endl ;

		// 읽을 파일
		ifstream stream(name_copy) ;
		if(stream.fail()) {
			cerr << "oepn failed " << endl ;
			break ;
		}

		Convert_Filename(File_name) ;

		while (!stream.eof())
		{
			// 저장할 파일들 0.txt 부터 시작한다.
			ofstream ostream(File_name);
			int new_line = 0 ;

			while (!stream.eof())
			{
				stream.getline(sentence, MIN);

				// 주석이 시작됐거나 시작이면
				if(sentence[0] == '{' || braket_ == true){
					braket_ = true ;
					// 문장의 마지막이 주석을 닫는것인지 확인.
					if(sentence[strlen(sentence)-1] == '}'){
						braket_ = false ;
					}
					continue ;
				}
				else {
					if (sentence[0] == NULL) new_line++ ;
					if(new_line == 2 ){
						// 파일을 저장한다.
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
