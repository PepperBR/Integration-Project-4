#pragma once

class GlobalID
{
private:
    static int id;

public:
    static int generateID();
};