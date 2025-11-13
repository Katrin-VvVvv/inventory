#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
	string name;
	string type;
	int level;
};



int main() {
	vector<Item> inventory;
	setlocale(LC_ALL, "");

	addItem(inventory, "Меч воина", "оружие", 5);
	addItem(inventory, "Кольчуга", "броня", 3);
	addItem(inventory, "Зелье здоровья", "зелье", 1);
	addItem(inventory, "Лук охотника", "оружие", 7);

	printInventory(inventory);

	sortByLevel(inventory);
	cout << "После сортировки по уровню:\n";
	printInventory(inventory);

	vector<Item> weapons = filterByType(inventory, "оружие");
	cout << "Только оружие:\n";
	printInventory(weapons);

	removeItem(inventory, "Зелье здоровья");
	cout << "После удаления зелья:\n";
	printInventory(inventory);

	return 0;
}
