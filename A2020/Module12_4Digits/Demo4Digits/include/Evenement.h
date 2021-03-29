#pragma once

class Evenement {
private:

protected:
    virtual void _executer() = 0;

public:
    virtual void Executer() = 0;
};
