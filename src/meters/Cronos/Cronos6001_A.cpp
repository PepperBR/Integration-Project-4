#include "meters/Cronos/Cronos6001_A.h"
#include "core/GlobalID.h"


Cronos6001_A::Cronos6001_A()
    : Cronos(GlobalID::generateID(), "6001 A")
{
};

Cronos6001_A::Cronos6001_A(const Cronos6001_A& other, int new_id)
    : Cronos(other, new_id) 
{
};

Cronos6001_A::~Cronos6001_A()
{
};

std::vector<double> & Cronos6001_A::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos6001_A::cloneMeter() const
{
    return std::make_unique<Cronos6001_A>(*this, GlobalID::generateID());
}
