#include "meters/Cronos/Cronos6021_L.h"
#include "core/GlobalID.h"


Cronos6021_L::Cronos6021_L()
    : Cronos(GlobalID::generateID(), "6021 L")
{
};

Cronos6021_L::Cronos6021_L(const Cronos6021_L& other, int new_id)
    : Cronos(other, new_id) 
{
};

Cronos6021_L::~Cronos6021_L()
{
};

std::vector<double> & Cronos6021_L::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Cronos6021_L::cloneMeter() const
{
    return std::make_unique<Cronos6021_L>(*this, GlobalID::generateID());
}
