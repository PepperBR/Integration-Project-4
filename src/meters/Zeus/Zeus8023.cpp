#include "meters/Zeus/Zeus8023.h"

Zeus8023::Zeus8023()
    : Zeus(3, "8023"){};

Zeus8023::Zeus8023(const Zeus8023 &other, int new_id)
    : Zeus(other, new_id){};

Zeus8023::~Zeus8023(){};

std::vector<double> &Zeus8023::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

std::shared_ptr<Meter> Zeus8023::cloneMeter(int unique_id) const
{
    return std::make_shared<Zeus8023>(*this, unique_id);
}
