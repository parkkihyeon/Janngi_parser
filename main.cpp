/*
    output :    ������ ������ �¸� �����丮
    history :   ����ġ ����ġ ���絹 ������ �屺����
    name :      ��,�� J    �� C    �� H    �� X
                �� P      �� K    �� S
                ���� ��ܲ ��  ��ة ��ة �� ���� ���� ��  ��� ��� ��
                ���� ���� ��  ���� ���� �� ���� ���� ��     */

#include "File_divide.h"
#include "parse.h"

int main()
{
	char file_name[100] ;
	int num, start_txt ;
	cout << "\n���� �̸��� ������ :" ;
	cin>> file_name  ;

	cout << "������ ������ ������ :" ;
	cin >> num ;
		
	cout << "������ ���� ���ڸ� ������ :" ;
	cin >> start_txt ;

  //  Devide_Doc(num+start_txt, file_name, start_txt);
    Parser();
    return 0;
}

