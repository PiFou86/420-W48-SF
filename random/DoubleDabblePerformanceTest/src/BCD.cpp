#include "BCD.h"

uint32_t double_dabble32(uint32_t n) {
    // On utilise un uint64_t comme tableau de bits
    // à droite c'est la valeur que l'on veut convertir (32 bits)
    // à gauche c'est la valeur BCD (32 bits)
    uint64_t bcd = n;
    for (int i = 0; i < NB_BITS_32; ++i) {
        for (int j = 0; j < NB_BITS_32; j += 4) {
            // Si le chiffre est supérieur à 4, on ajoute 3
            if (((bcd >> (NB_BITS_32 + j)) & 0xF) > 4) {
                bcd += ((uint64_t)3 << (NB_BITS_32 + j));
            }
        }
        bcd <<= 1;
    }
    
    bcd >>= NB_BITS_32;

    return (uint32_t)bcd;
}

uint16_t double_dabble16(uint16_t n) {
    // On utilise un uint32_t comme tableau de bits
    // à droite c'est la valeur que l'on veut convertir (16 bits)
    // à gauche c'est la valeur BCD (16 bits)
    uint32_t bcd = n;
    for (int i = 0; i < NB_BITS_16; ++i) {
        for (int j = 0; j < NB_BITS_16; j += 4) {
            // Si le chiffre est supérieur à 4, on ajoute 3
            if (((bcd >> (NB_BITS_16 + j)) & 0xF) > 4) {
                bcd += ((uint32_t)3 << (NB_BITS_16 + j));
            }
        }
        bcd <<= 1;
    }
    
    bcd >>= NB_BITS_16;

    return (uint16_t)bcd;
}

uint8_t double_dabble8(uint8_t n) {
    // On utilise un uint16_t comme tableau de bits
    // à droite c'est la valeur que l'on veut convertir (8 bits)
    // à gauche c'est la valeur BCD (8 bits)
    uint16_t bcd = n;
    for (int i = 0; i < NB_BITS_8; ++i) {
        for (int j = 0; j < NB_BITS_8; j += 4) {
            // Si le chiffre est supérieur à 4, on ajoute 3
            if (((bcd >> (NB_BITS_8 + j)) & 0xF) > 4) {
                bcd += ((uint16_t)3 << (NB_BITS_8 + j));
            }
        }
        bcd <<= 1;
    }
    
    bcd >>= NB_BITS_8;

    return (uint8_t)bcd;
}

String bcd2String(uint8_t n) {
    bool debute = false;
    
    String s;
    // 8 bits - 4 bits par chiffre
    for (int i = 4; i >= 0; i -= 4)
    {
        uint8_t c = n >> i;
        c &= 0x0F;

        if (c > 9) {
            return "Error";
        }
        if (c != 0) {
            debute = true;
        }
        if (debute) {
            s += (char)(c | 0x30);
        }
    }
    
    if (s.length() == 0) {
        return "0";
    }

    return s;
}

String bcd2String(uint16_t n) {
    bool debute = false;
    
    String s;
    // 16 bits - 4 bits par chiffre
    for (int i = 12; i >= 0; i -= 4)
    {
        uint8_t c = n >> i;
        c &= 0x0F;

        if (c > 9) {
            return "Error";
        }
        if (c != 0) {
            debute = true;
        }
        if (debute) {
            s += (char)(c | 0x30);
        }
    }
    
    if (s.length() == 0) {
        return "0";
    }

    return s;
}

String bcd2String(uint32_t n) {
    bool debute = false;
    
    String s;
    // 32 bits - 4 bits par chiffre
    for (int i = 28; i >= 0; i -= 4)
    {
        uint8_t c = n >> i;
        c &= 0x0F;

        if (c > 9) {
            return "Error";
        }
        if (c != 0) {
            debute = true;
        }
        if (debute) {
            s += (char)(c | 0x30);
        }
    }
    
    if (s.length() == 0) {
        return "0";
    }

    return s;
}

String int2String(uint32_t n) {
    String s;
    while (n > 0) {
        s = (char)((n % 10) | 0x30) + s;
        n /= 10;
    }
    if (s.length() == 0) {
        return "0";
    }
    return s;
}