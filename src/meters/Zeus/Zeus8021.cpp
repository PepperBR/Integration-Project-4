#include "meters/Zeus/Zeus8021.h"

Zeus8021::Zeus8021()
    : Zeus(2, "8021"){};

Zeus8021::Zeus8021(const Zeus8021 &other, int new_id)
    : Zeus(other, new_id){};

Zeus8021::~Zeus8021(){};

std::vector<double> &Zeus8021::getPhaseValues()
{
    return SinglePhaseMeter::getPhaseValues();
};

std::shared_ptr<Meter> Zeus8021::cloneMeter(int unique_id) const
{
    return std::make_shared<Zeus8021>(*this, unique_id);
}
