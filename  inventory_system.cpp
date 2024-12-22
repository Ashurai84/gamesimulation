#include "GameClasses.h"
#include <iostream>
#include <utility>
#include <vector> 

// Item class constructor
Item::Item(std::string name, int quantity, float price)
    : name(std::move(name)), quantity(quantity), price(price) {}

std::string Item::get_name() const { return name; }
int Item::get_quantity() const { return quantity; }
void Item::set_quantity(int new_quantity) { quantity = new_quantity; }
float Item::get_price() const { return price; }
bool Item::is_match(const std::string &other) { return name == other; }

// Inventory class constructor and destructor
Inventory::Inventory() : total_money(0) {}

Inventory::~Inventory() {
    for (auto item : items) {
        delete item; // Properly clean up memory
    }
}

void Inventory::add_item() {
    std::string name;
    int quantity;
    float price;

    std::cout << "\nEnter item name: ";
    std::cin >> name;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cout << "Enter price: ";
    std::cin >> price;

    items.push_back(new Item(name, quantity, price)); // Dynamically allocated Item
    std::cout << "\nItem added successfully!";
}

void Inventory::list_items() {
    if (items.empty()) {
        std::cout << "\nInventory is empty.";
        return;
    }

    for (const auto& item : items) {
        std::cout << "\nItem Name: " << item->get_name();
        std::cout << "\nQuantity: " << item->get_quantity();
        std::cout << "\nPrice: " << item->get_price();
        std::cout << "\n";
    }
}

void Inventory::sell_item() {
    std::string item_name;
    std::cout << "\nEnter the item name to sell: ";
    std::cin >> item_name;

    for (int i = 0; i < items.size(); i++) {
        if (items[i]->is_match(item_name)) {
            remove_item(i);
            return;
        }
    }
    std::cout << "\nItem not found in inventory.";
}

void Inventory::remove_item(int item_index) {
    int input_quantity;
    Item* item = items[item_index];

    std::cout << "\nEnter number of items to sell: ";
    std::cin >> input_quantity;

    int current_quantity = item->get_quantity();
    if (input_quantity <= current_quantity) {
        float item_price = item->get_price();
        float money_earned = item_price * input_quantity;

        item->set_quantity(current_quantity - input_quantity);

        if (item->get_quantity() == 0) {
            delete item; // Properly delete the item to prevent memory leaks
            items.erase(items.begin() + item_index); // Remove item from vector
            std::cout << "\nItem completely removed from inventory.";
        } else {
            std::cout << "\nItems sold.";
        }

        total_money += money_earned;
        std::cout << "\nMoney received: " << money_earned;
    } else {
        std::cout << "\nCannot sell more items than you have.";
    }
}
