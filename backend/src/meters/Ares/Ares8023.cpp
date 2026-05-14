#include "meters/Ares/Ares8023.h"

Ares8023::Ares8023()
    : Ares(13, "8023", Phase::PhaseC){};

Ares8023::Ares8023(const Ares8023 &other, const int &new_id)
    : Ares(other, new_id){};

Ares8023::~Ares8023(){};

std::shared_ptr<Meter> Ares8023::cloneMeter(int unique_id) const
{
    return std::make_shared<Ares8023>(*this, unique_id);
}
