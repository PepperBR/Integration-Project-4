#include "meters/Cronos/Cronos6003.h"
#include "core/GlobalID.h"


Cronos6003::Cronos6003()
    : Cronos(GlobalID::generateID(), "6003")
{
};

Cronos6003::Cronos6003(const Cronos6003& other, int new_id)
    : Cronos(other, new_id) 
{
};

Cronos6003::~Cronos6003()
{
};

std::vector<double> & Cronos6003::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos6003::cloneMeter() const
{
    return std::make_unique<Cronos6003>(*this, GlobalID::generateID());
};