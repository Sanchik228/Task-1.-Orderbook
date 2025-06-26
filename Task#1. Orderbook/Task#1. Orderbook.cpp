#include <iostream>

struct Order {
	int user_id;
	int amount;
	int prise;
	bool side;

	Order(int uID, int amt, int pri, bool sd)
		: user_id(uID), amount(amt), prise(pri), side(sd) {}
};



int main() {


	return 0;
}