#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

const bool BUY = true;
const bool SELL = false;

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

struct BuyCompere {
	bool operator() (const Order& a, const Order& b) {
		return a.prise < b.prise;
	}
};

struct SellCompere {
	bool operator() (const Order& a, const Order& b) {
		return a.prise > b.prise;
	}
};

class Orderbook {
private:
	std::priority_queue<Order, std::vector<Order>, BuyCompere> buyOrders;
	std::priority_queue<Order, std::vector<Order>, SellCompere> sellOrders;

	void matchBuy(Order buyOrder) {
		while (!sellOrders.empty() && buyOrder.amount > 0 
			&& sellOrders.top().prise >= buyOrder.prise) {
			Order sellOrder = sellOrders.top();
			sellOrders.pop();

			int tradedAmount = std::min(buyOrder.amount, sellOrder.amount);
			int tradePrise = sellOrder.prise;

			int USD = tradedAmount * tradePrise;

			std::cout << "Trade executed:\n";
			BalanceChange{ buyOrder.user_id, -USD, "USD" }.print();
			BalanceChange{ buyOrder.user_id, +tradedAmount, "UAH" }.print();

			BalanceChange{ sellOrder.user_id, +USD, "USD" }.print();
			BalanceChange{ sellOrder.user_id, -tradedAmount, "UAH" }.print();

			buyOrder.amount -= tradedAmount;
			sellOrder.amount -= tradedAmount;

			if (sellOrder.amount > 0) {
				sellOrders.push(sellOrder); // повертаємо залишок
			}
		}
		if (buyOrder.amount > 0) {
			buyOrders.push(buyOrder);
		}
	}
	void matchSell(Order sellOrder) {
		while (!buyOrders.empty() && sellOrder.amount > 0
			&& buyOrders.top().prise >= sellOrder.prise) {
			Order buyOrder = buyOrders.top();
			buyOrders.pop();

			int tradedAmount = std::min(sellOrder.amount, buyOrder.amount);
			int tradePrise = buyOrder.prise;

			int USD = tradedAmount * tradePrise;

			std::cout << "Trade executed:\n";
			BalanceChange{ sellOrder.user_id, -USD, "USD" }.print();
			BalanceChange{ sellOrder.user_id, +tradedAmount, "UAH" }.print();

			BalanceChange{ buyOrder.user_id, +USD, "USD" }.print();
			BalanceChange{ buyOrder.user_id, -tradedAmount, "UAH" }.print();

			sellOrder.amount -= tradedAmount;
			buyOrder.amount -= tradedAmount;

			if (buyOrder.amount > 0) {
				buyOrders.push(sellOrder); // повертаємо залишок
			}
		}
		if (sellOrder.amount > 0) {
			sellOrders.push(sellOrder);
		}
	}
public:
	void addOrder(const Order& order) {
		if (order.side == BUY) {
			matchBuy(order);
		}
		else {
			matchSell(order);
		}
	}
};

int main() {


	return 0;
}