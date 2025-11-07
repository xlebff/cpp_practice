/* —оставьте перегруженные функции дл€ расчета итоговой стоимости товара Ц дл€ товара с ценой и
количеством; дл€ товара с ценой, количеством и скидкой; дл€ товара с ценой и скидкой.

#include <iostream>
#include <string>

using namespace std;

double totalCost(const double cost, const int quantity) {
	return cost * quantity;
}

double totalCost(const double cost, const int quantity, float sale) {
	return (cost * quantity) * (1 - sale / 100);
}

double totalCost(const double cost, float sale) {
	return cost * (1 - sale / 100);
}

int main() {
	const char ITEM[] = "Takopi";
	const double PRICE = 45.4;
	const int QUANTITY = 4;
	const float SALE = 40;

	cout << ITEM << ": " << totalCost(PRICE, SALE) << endl;

	return 0;
} */