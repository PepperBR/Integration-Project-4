#include "meters/Cronos/Cronos6021_A.h"

Cronos6021_A::Cronos6021_A()
    : Cronos(9, "6021 A", Phase::PhaseA){};

Cronos6021_A::Cronos6021_A(const Cronos6021_A &other, const int &new_id)
    : Cronos(other, new_id){};

Cronos6021_A::~Cronos6021_A(){};

std::shared_ptr<Meter> Cronos6021_A::cloneMeter(int unique_id) const
{
    return std::make_shared<Cronos6021_A>(*this, unique_id);
}
