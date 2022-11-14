#include "Header.h"

int main()
{
	Hero hero;
	cout << "Nhap thong tin hero: " << endl;
	cin >> hero;
	cout << "Thong tin anh hung: " << endl;
	cout << hero;
	cout << "Cac ky nang anh hung co the hoc duoc: " << endl;
	hero.SkillCanLearn();
	return 0;

}