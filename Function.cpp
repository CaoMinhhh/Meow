#include "Header.h"

Skill::Skill()
{
	this->skillName = "None";
	this->skillLevel = 0;
}

Skill::Skill(string skillName, unsigned int skillLevel)
{
	this->skillName = skillName;
	this->skillLevel = skillLevel;
}

Skill::~Skill() {}
Skill::Skill(const Skill& skill)
{
	this->skillName = skill.skillName;
	this->skillLevel = skill.skillLevel;
}

void Skill::SetSkillName(string skillName)
{
	this->skillName = skillName;
}

void Skill::SetSkillLevel(unsigned int skillLevel)
{
	this->skillLevel = skillLevel;
}

string Skill::getSkillName()
{
	return this->skillName;
}

unsigned int Skill::GetSkillLevel()
{
	return this->skillLevel;
}

istream& operator>>(istream& MySkill, Skill& skill)
{
	//MySkill.ignore();
	string skillName;
	unsigned int skillLevel;
	cout << "Nhap vao ten ky nang: ";
	getline(MySkill, skillName);
	cout << "Nhap vao cap do ky nang: ";
	MySkill >> skillLevel;
	skill.SetSkillName(skillName);
	skill.SetSkillLevel(skillLevel);
	MySkill.ignore();
	return MySkill;
}

ostream& operator<<(ostream& MySkill, Skill& skill)
{
	MySkill << skill.getSkillName() << " - " << "LV: " << skill.GetSkillLevel() << endl;
	return MySkill;
}

Hero::Hero()
{
	this->heroName = "None";
	this->heroHealth = 0;
	this->heroMana = 0;
	this->heroLevel = 0;
	Skill* s = new Skill();
	this->skillList.push_back(s);
}

Hero::Hero(string heroName, unsigned int heroHealth, unsigned int heroMana, unsigned int heroLevel, vector<Skill*> List)
{
	this->heroName = heroName;
	this->heroHealth = heroHealth;
	this->heroMana = heroMana;
	this->heroLevel = heroLevel;
	for (auto& x : List)
	{
		this->skillList.push_back(x);
	}
}

Hero::~Hero()
{
	this->skillList.clear();
}

void Hero::setHeroName(string heroName)
{
	this->heroName = heroName;
}

void Hero::setHeroHealth(unsigned int heroHealth)
{
	this->heroHealth = heroHealth;
}

void Hero::setHeroMana(unsigned int heroMana)
{
	this->heroMana = heroMana;
}

void Hero::setHeroLevel(unsigned int heroLevel)
{
	this->heroLevel = heroLevel;
}

void Hero::setSkillList(vector<Skill*> List)
{
	for (auto& x : List)
		this->skillList.push_back(x);
}

string Hero::getHeroName()
{
	return this->heroName;
}

unsigned int Hero::getHeroHealth()
{
	return this->heroHealth;
}

unsigned int Hero::getHeroMana()
{
	return this->heroMana;
}

unsigned int Hero::getHeroLevel()
{
	return this->heroLevel;
}

vector<Skill*> Hero::getSkillList()
{
	return this->skillList;
}

istream& operator>>(istream& MyHero, Hero& hero)
{
	string heroName;
	unsigned int heroHealth;
	unsigned int heroMana;
	unsigned int heroLevel;
	vector<Skill*> skillList;
	cout << "Nhap vao ten Hero: ";
	getline(MyHero, heroName);
	cout << "Nhap vao gioi han mau: ";
	MyHero >> heroHealth;
	cout << "Nhap vao gioi han mana: ";
	MyHero >> heroMana;
	cout << "Nhap vao gioi han level: ";
	MyHero >> heroLevel;
	int n;
	cout << "Nhap vao so luong chieu thuc: ";
	cin >> n;
	MyHero.ignore();
	Skill s;
	for (int i = 0; i < n; i++)
	{
		//MyHero.ignore();
		MyHero >> s;
		Skill* input = new Skill(s);
		skillList.push_back(input);
	}
	hero.setHeroName(heroName);
	hero.setHeroHealth(heroHealth);
	hero.setHeroMana(heroMana);
	hero.setHeroLevel(heroLevel);
	hero.setSkillList(skillList);
	return MyHero;
}

ostream& operator<<(ostream& MyHero, Hero& hero)
{
	MyHero << "Name: " << hero.getHeroName() << endl;
	MyHero << "Health: " << hero.getHeroHealth() << endl;
	MyHero << "Mana: " << hero.getHeroMana() << endl;
	MyHero << "Level: " << hero.getHeroLevel() << endl;
	for (int i = 1; i < hero.getSkillList().size(); i++)
		cout << *hero.getSkillList()[i] << endl;
	return MyHero;
}

bool Hero::CheckSkill(Skill skill)
{
	if (this->getHeroLevel() >= skill.GetSkillLevel())
		return true;
	else
		return false;
}

void Hero::SkillCanLearn()
{
	for (int i = 1; i < this->getSkillList().size(); i++)
	{
		if (CheckSkill(*this->getSkillList()[i]))
			cout << *this->getSkillList()[i] << endl;
	}
}