#include "core/GlobalID.h"

int GlobalID::id = 0;

int GlobalID::generateID()
{
    return ++id;
}
