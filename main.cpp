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

void addItem(vector<Item>& inv, const string& name, const string& type, int level) {
	inv.push_back({ name, type, level });
}

bool removeItem(vector<Item>& inv, const string& name) {
	auto it = find_if(inv.begin(), inv.end(),
		[&name](const Item& item) { return item.name == name; });

	if (it != inv.end()) {
		inv.erase(it);
		return true;
	}
	return false;
}

void printInventory(const vector<Item>& inv) {
	cout << "\n--- Инвентарь ---\n";
	for (const auto& item : inv) {
		cout << "Название: " << item.name
			<< ", Тип: " << item.type
			<< ", Уровень: " << item.level << endl;
	}
	cout << "--- Конец инвентаря ---\n\n";
}

void sortByLevel(vector<Item>& inv) {
	sort(inv.begin(), inv.end(),
		[](const Item& a, const Item& b) { return a.level < b.level; });
}

vector<Item> filterByType(const vector<Item>& inv, const string& type) {
	vector<Item> filtered;
	copy_if(inv.begin(), inv.end(), back_inserter(filtered),
		[&type](const Item& item) { return item.type == type; });
	return filtered;
}

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
