#include "meters/Zeus/Zeus8021.h"
#include "core/GlobalID.h"


Zeus8021::Zeus8021()
    : Zeus(GlobalID::generateID(), "8021")
{
};

Zeus8021::Zeus8021(const Zeus8021& other, int new_id)
    : Zeus(other, new_id)
{
};

Zeus8021::~Zeus8021()
{
};

std::vector<double> & Zeus8021::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Zeus8021::cloneMeter() const
{
    return std::make_unique<Zeus8021>(*this, GlobalID::generateID());
}


