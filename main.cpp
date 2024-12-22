#include <iostream>
#include "GameClasses.h"

 
GameObject::GameObject(const std::string& name, int id) : name(name), id(id) {}
GameObject::~GameObject() {}
std::string GameObject::getName() const { return name; }
int GameObject::getId() const { return id; }
void GameObject::displayInfo() const { std::cout << "Name: " << name << ", ID: " << id << std::endl; }

 
Player::Player(const std::string& name, int id, int health, int score)
    : GameObject(name, id), health(health), score(score) {}
Player::~Player() {}
int Player::getHealth() const { return health; }
int Player::getScore() const { return score; }
std::vector<std::string> Player::getInventory() const { return inventory; }
void Player::setHealth(int health) { this->health = health; }
void Player::setScore(int score) { this->score = score; }
void Player::addItem(const std::string& item) { inventory.push_back(item); }
void Player::removeItem(const std::string& item) {
    inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());
}
void Player::displayInfo() const {
    std::cout << "Player Info:\nName: " << name << "\nHealth: " << health
              << "\nScore: " << score << "\nInventory: ";
    for (const auto& item : inventory) std::cout << item << " ";
    std::cout << std::endl;
}

// Constructor definitions for PowerUp
PowerUp::PowerUp(const std::string& name, int id, const std::string& type, int duration)
    : GameObject(name, id), type(type), duration(duration), isActive(false) {}
PowerUp::~PowerUp() {}
std::string PowerUp::getType() const { return type; }
int PowerUp::getDuration() const { return duration; }
bool PowerUp::getIsActive() const { return isActive; }
void PowerUp::activate() { isActive = true; }
void PowerUp::deactivate() { isActive = false; }
void PowerUp::displayInfo() const {
    std::cout << "Power-Up Info:\nName: " << name << "\nType: " << type
              << "\nDuration: " << duration << " seconds\nActive: " << (isActive ? "Yes" : "No") << std::endl;
}

// Constructor definitions for NPC
NPC::NPC(const std::string& name, int id, const std::string& role)
    : GameObject(name, id), role(role) {}
NPC::~NPC() {}
std::string NPC::getRole() const { return role; }
std::vector<std::string> NPC::getDialogues() const { return dialogues; }
void NPC::addDialogue(const std::string& dialogue) { dialogues.push_back(dialogue); }
void NPC::removeDialogue(const std::string& dialogue) {
    dialogues.erase(std::remove(dialogues.begin(), dialogues.end(), dialogue), dialogues.end());
}
void NPC::interact() const {
    if (!dialogues.empty()) std::cout << name << " says: " << dialogues.front() << std::endl;
    else std::cout << name << " has nothing to say." << std::endl;
}
void NPC::displayInfo() const {
    std::cout << "NPC Info:\nName: " << name << "\nRole: " << role << "\nDialogues: ";
    for (const auto& dialogue : dialogues) std::cout << dialogue << " ";
    std::cout << std::endl;
}

// Main function
int main() {
    // Create a Player object
    Player player("Hero", 1, 100, 50);
    player.addItem("Sword");
    player.addItem("Shield");
    player.setHealth(90);
    player.displayInfo();

    // Create a PowerUp object
    PowerUp speedBoost("Speed Boost", 2, "Speed", 10);
    speedBoost.activate();
    speedBoost.displayInfo();

    // Create an NPC object
    NPC shopkeeper("Shopkeeper", 3, "Merchant");
    shopkeeper.addDialogue("Welcome to my shop!");
    shopkeeper.addDialogue("Take a look at my wares.");
    shopkeeper.displayInfo();
    shopkeeper.interact();

    return 0;
}
