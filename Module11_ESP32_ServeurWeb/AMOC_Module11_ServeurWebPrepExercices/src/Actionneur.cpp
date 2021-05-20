#include "Actionneur.h"

Actionneur::Actionneur(int const& p_id, String const& p_description)
    : m_id(p_id), m_description(p_description) {}

const String& Actionneur::description() const { return this->m_description; }

int Actionneur::id() const { return this->m_id; }
