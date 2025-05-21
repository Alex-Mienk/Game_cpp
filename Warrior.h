#pragma once

#include "Character.h"

class Warrior : public Character {

protected:
    int shield_durability;

public:
    Warrior() = delete;
    Warrior(const std::string& name, int max_health_points, int shield_durability);

    void Attack(Character& character);
    void Rest(int hours) override;
    void TakeDamage(int damage) override;
    void GetHealed(int heal);
protected:
    void Serialize(std::ostream& os) const override;

public:
    //PART 6
    //Character* Clone();
};
