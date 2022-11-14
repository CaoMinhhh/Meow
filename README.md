# Meow
for .h : 
#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class Skill
{
private:
	string skillName;
	unsigned int skillLevel;
public:
	Skill();
	Skill(string, unsigned int);
	~Skill();
	Skill(const Skill&);
	void SetSkillName(string);
	string getSkillName();
	void SetSkillLevel(unsigned int);
	unsigned int GetSkillLevel();
};
istream& operator>>(istream&, Skill&);
ostream& operator<<(ostream&, Skill&);


class Hero
{
private:
	string heroName;
	unsigned int heroHealth;
	unsigned int heroMana;
	unsigned int heroLevel;
	vector<Skill*> skillList;
public:
	Hero();
	Hero(string, unsigned int, unsigned int, unsigned int, vector<Skill*>);
	~Hero();
	void setHeroName(string);
	string getHeroName();
	void setHeroHealth(unsigned int);
	unsigned int getHeroHealth();
	void setHeroMana(unsigned int);
	unsigned int getHeroMana();
	void setHeroLevel(unsigned int);
	unsigned int getHeroLevel();
	void setSkillList(vector<Skill*>);
	vector<Skill*> getSkillList();
	bool CheckSkill(Skill);
	void SkillCanLearn();
};

istream& operator>>(istream&, Hero&);
ostream& operator<<(ostream&, Hero&);
