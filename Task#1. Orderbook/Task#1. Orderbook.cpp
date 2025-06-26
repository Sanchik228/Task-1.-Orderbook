#include <iostream>

struct Order {
	int user_id;
	int amount;
	int prise;
	bool side;

	Order(int uID, int amt, int pri, bool sd)
		: user_id(uID), amount(amt), prise(pri), side(sd) {}
};

struct BalanceChange {
	int user_id;
	int value;
	std::string currency;

	void print() const {
		std::cout << "BalanceChange{user_id: " << user_id << ", value: " << value
			<< ", currency: " << currency << std::endl;
	}
};

int main() {


	return 0;
}