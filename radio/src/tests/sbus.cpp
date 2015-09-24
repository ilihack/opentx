/*
 * Authors (alphabetical order)
 * - Andre Bernet <bernet.andre@gmail.com>
 * - Andreas Weitl
 * - Bertrand Songis <bsongis@gmail.com>
 * - Bryan J. Rentoul (Gruvin) <gruvin@gmail.com>
 * - Cameron Weeks <th9xer@gmail.com>
 * - Erez Raviv
 * - Gabriel Birkus
 * - Jean-Pierre Parisy
 * - Karl Szmutny
 * - Michael Blandford
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rob Thomson
 * - Romolo Manfredini <romolo.manfredini@gmail.com>
 * - Thomas Husterer
 *
 * opentx is based on code named
 * gruvin9x by Bryan J. Rentoul: http://code.google.com/p/gruvin9x/,
 * er9x by Erez Raviv: http://code.google.com/p/er9x/,
 * and the original (and ongoing) project by
 * Thomas Husterer, th9x: http://code.google.com/p/th9x/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "gtests.h"

#if defined(SBUS)
TEST(SBus, createSbusFrame)
{
  int16_t pulsesStart[NUM_TRAINER];
  int16_t pulsesEnd[NUM_TRAINER];
  uint8_t sbus[SBUS_MAX_FRAME_SIZE];

  memset(sbus, 0, sizeof(sbus));
  for (int i=0; i<NUM_TRAINER; i++) {
    pulsesStart[i] = -1024 + (2048 / NUM_TRAINER) * i;
  }

  createSbusFrame(sbus, pulsesStart);
  processSbusFrame(sbus, pulsesEnd, SBUS_MAX_FRAME_SIZE);

  for (int i=0; i<NUM_TRAINER; i++) {
    EXPECT_TRUE(abs(pulsesStart[i]/2 - pulsesEnd[i]) <= 1);
  }
}
#endif

