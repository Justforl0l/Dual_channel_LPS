#ifndef FUSES_H_
#define FUSES_H_

#include "avr/io.h"

FUSES =
{
    .low = LFUSE_DEFAULT,
    .high = (FUSE_BOOTSZ1 & FUSE_BOOTSZ0 & FUSE_WDTON & FUSE_SPIEN)
};

LOCKBITS = LOCKBITS_DEFAULT;

#endif // FUSES_H_