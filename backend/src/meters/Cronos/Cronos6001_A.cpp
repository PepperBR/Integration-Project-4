#include "meters/Cronos/Cronos6001_A.h"

Cronos6001_A::Cronos6001_A()
    : Cronos(11, "6001 A", Phase::PhaseC){};

Cronos6001_A::Cronos6001_A(const Cronos6001_A &other, const int &new_id)
    : Cronos(other, new_id){};

Cronos6001_A::~Cronos6001_A(){};

std::shared_ptr<Meter> Cronos6001_A::cloneMeter(int unique_id) const
{
    return std::make_shared<Cronos6001_A>(*this, unique_id);
}
