#include "meters/Ares/Ares8023_15.h"

Ares8023_15::Ares8023_15()
    : Ares(16, "8023 15", Phase::PhaseA){};

Ares8023_15::Ares8023_15(const Ares8023_15 &other, const int &new_id)
    : Ares(other, new_id){};

Ares8023_15::~Ares8023_15(){};

std::shared_ptr<Meter> Ares8023_15::cloneMeter(int unique_id) const
{
    return std::make_unique<Ares8023_15>(*this, unique_id);
}
