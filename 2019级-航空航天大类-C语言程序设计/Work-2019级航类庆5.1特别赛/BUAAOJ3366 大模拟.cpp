#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
#include<iomanip>
using namespace std;

double hunger, HungerLimit;//饥饿值与上限
double san, SanLimit;//精神值与上限
double hp, HPLimit;//生命值与上限
double sanBuff;//精神值永久buff
double hpBuff;//生命值永久buff
bool equipped;//装备
double singleRate;
double remainPower;
double Timer;//表示计时器,指当前角色信息对应哪个时刻
void printInfo() {//用于与样例解释对拍
	cout << fixed << setprecision(2) << hunger << " " << san << " " << hp << endl;
}
string in;
string Instr;
double t, a, b, c;
int n;
bool isdead;//如果True 则直接break不接受后续指令 否则最后输出WIN

inline void update(double newT) { //执行指令之前,更新角色属性至newT
	double passTime = newT - Timer;
	if (hunger < passTime * 10) {
		double hungerTime = hunger / 10;
		double lifeTime = passTime - hungerTime;
		hunger = 0;
		hp += hungerTime * hpBuff;
		if (hp > HPLimit)hp = HPLimit;
		if (hp <= 0) { isdead = true; return; }
		hp += lifeTime * (hpBuff - 60);
		if (hp > HPLimit)hp = HPLimit;
		if (hp <= 0) { isdead = true; return; }
	}
	else {
		hunger -= passTime * 10;
		hp += passTime * hpBuff;
		if (hp > HPLimit)hp = HPLimit;
		if (hp <= 0) { isdead = true; return; }
	}
	san += passTime * sanBuff;
	if (san > SanLimit)san = SanLimit;
	if (san < 0)san = 0;
	Timer = newT;
}
inline void handleEquip(double a, double b) {//装上防护甲
	equipped = true;
	singleRate = a / 100.0;
	remainPower = b;
}
inline void handleEat(double a, double b, double c) {
	hunger += a, san += b, hp += c;
	if (hunger > HungerLimit)hunger = HungerLimit;
	if (hunger < 0)hunger = 0;
	if (san > SanLimit)san = SanLimit;
	if (san < 0)san = 0;
	if (hp > HPLimit)hp = HPLimit;
	if (hp <= 0)isdead = true;
}
inline void handleAttack(double a) {
	if (!equipped)hp -= a;
	else {
		if (singleRate * a >= remainPower) {
			hp -= (a - remainPower);
			remainPower = 0.0, singleRate = 0.0;
			equipped = false;
		}
		else {
			hp -= (a - singleRate * a);
			remainPower -= singleRate * a;
		}
	}
	if (hp <= 0)isdead = true;
}
inline void handleSan(double a) {
	sanBuff += a;
}
inline void handleHP(double a) {
	hpBuff += a;
}
inline void query(int n) {
	if (n == 1)cout << fixed << setprecision(2) << hunger << endl;
	if (n == 2)cout << fixed << setprecision(2) << san << endl;
	if (n == 3)cout << fixed << setprecision(2) << hp << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	getline(cin, in);
	stringstream s1(in);
	s1 >> Instr >> a >> b >> c;//第一个必然是start
	hunger = HungerLimit = a;
	san = SanLimit = b;
	hp = HPLimit = c;
	while (getline(cin, in)) {
		s1 = stringstream(in);
		s1 >> Instr >> t;//输入指令共有的指令名称和时间
		update(t);
		if (isdead)break;//一旦update导致死亡,直接break
		if (Instr == "EQUIP") {
			s1 >> a >> b;
			handleEquip(a, b);
		}
		else if (Instr == "EAT") {
			s1 >> a >> b >> c;
			handleEat(a, b, c);
		}
		else if (Instr == "BEATTACK") {
			s1 >> a;
			handleAttack(a);
		}
		else if (Instr == "SAN_UP") {
			s1 >> a;
			handleSan(a);
		}
		else if (Instr == "SAN_DOWN") {
			s1 >> a;
			handleSan(-a);
		}
		else if (Instr == "HP_UP") {
			s1 >> a;
			handleHP(a);
		}
		else if (Instr == "HP_DOWN") {
			s1 >> a;
			handleHP(-a);
		}
		else {
			s1 >> n;
			query(n);
		}
		if (isdead)break;
	}
	if (isdead)puts("GAME_OVER");
	else puts("WIN");
}