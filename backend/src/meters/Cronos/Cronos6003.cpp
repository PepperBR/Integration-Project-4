#include "meters/Cronos/Cronos6003.h"

Cronos6003::Cronos6003()
    : Cronos(10, "6003", Phase::PhaseB){};

Cronos6003::Cronos6003(const Cronos6003 &other, const int &new_id)
    : Cronos(other, new_id){};

Cronos6003::~Cronos6003(){};

std::shared_ptr<Meter> Cronos6003::cloneMeter(int unique_id) const
{
    return std::make_shared<Cronos6003>(*this, unique_id);
};