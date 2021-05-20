#pragma once
#include <Arduino.h>

class Actionneur {

public:
    Actionneur(int const &p_id, String const& p_description);

    const String& description() const;
    int id() const;

    virtual void allumer() = 0;
    virtual void eteindre() = 0;
    virtual bool estAllume() const = 0;

private:
    int m_id;
    String m_description;
};