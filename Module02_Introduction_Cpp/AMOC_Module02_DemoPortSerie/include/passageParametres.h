#pragma once

#include "Flasher.h"

void passageDeParametres1(int p_v1, int &p_r1, int *p_p1);
void passageDeParametresCopie(Flasher p_flasher);
void passageDeParametresReference(Flasher& p_flasher);
void passageDeParametresPointeur(Flasher* p_flasher);
