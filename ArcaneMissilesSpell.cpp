#include "ArcaneMissilesSpell.h"
#include "Character.h"

void ArcaneMissilesSpell::Cast(Character &caster, Character &target)
{
    for (int i = 0; i < MISSILES_COUNT; i++){
        caster.Attack(target);
    }
}

void ArcaneMissilesSpell::Serialize(std::ostream& os) const
{
    os << "ArcaneMissiles";
}

Spell *ArcaneMissilesSpell::Clone() const
{
    return new ArcaneMissilesSpell(*this);
}
