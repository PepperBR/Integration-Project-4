#include "meters/Ares/Ares7021.h"
#include "core/GlobalID.h"

Ares7021::Ares7021()
    : Ares(GlobalID::generateID(), "7021")
{
};


Ares7021::Ares7021(const Ares7021& other, int new_id)
    : Ares(other, new_id) 
{
};

Ares7021::~Ares7021()
{
};

std::vector<double> & Ares7021::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Ares7021::cloneMeter() const
{
    return std::make_unique<Ares7021>(*this, GlobalID::generateID());
}

