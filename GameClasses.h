 #ifndef GAME_CLASSES_H
#define GAME_CLASSES_H

#include <string>
#include <vector>

class GameObject {
protected:
    std::string name;
    int id;

public:
    GameObject(const std::string& name, int id);
    virtual ~GameObject();
    std::string getName() const;
    int getId() const;
    virtual void displayInfo() const;
};

class Player : public GameObject {
private:
    int health;
    int score;
    std::vector<std::string> inventory;

public:
    Player(const std::string& name, int id, int health, int score);
    ~Player();
    int getHealth() const;
    int getScore() const;
    std::vector<std::string> getInventory() const;
    void setHealth(int health);
    void setScore(int score);
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
    void displayInfo() const override;
};

class PowerUp : public GameObject {
private:
    std::string type;
    int duration;
    bool isActive;

public:
    PowerUp(const std::string& name, int id, const std::string& type, int duration);
    ~PowerUp();
    std::string getType() const;
    int getDuration() const;
    bool getIsActive() const;
    void activate();
    void deactivate();
    void displayInfo() const override;
};

class NPC : public GameObject {
private:
    std::string role;
    std::vector<std::string> dialogues;

public:
    NPC(const std::string& name, int id, const std::string& role);
    ~NPC();
    std::string getRole() const;
    std::vector<std::string> getDialogues() const;
    void addDialogue(const std::string& dialogue);
    void removeDialogue(const std::string& dialogue);
    void interact() const;
    void displayInfo() const override;
};

#endif
