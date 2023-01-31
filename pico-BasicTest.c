/*
 *  CUnit - A Unit testing framework library for C.
 *  Copyright (C) 2004  Anil Kumar, Jerry St.Clair
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#if defined(PICO_NO_HARDWARE) && PICO_NO_HARDWARE == 0
#include "pico/bootrom.h"
#endif

#include "Basic.h"
#include "ExampleTests.h"

int main() {
  stdio_init_all();

  CU_BasicRunMode mode = CU_BRM_VERBOSE;
  CU_ErrorAction error_action = CUEA_IGNORE;

  if (CU_initialize_registry()) {
    printf("\nInitialization of Test Registry failed.");
  }
  else {
    AddTests();
    CU_basic_set_mode(mode);
    CU_set_error_action(error_action);
    printf("\nTests completed with return value %d.\n", CU_basic_run_tests());
    CU_cleanup_registry();
  }

  printf("\nCUnit finished\n");
  sleep_ms(1000);
#if defined(PICO_NO_HARDWARE) && PICO_NO_HARDWARE == 0
  printf("reboot...\n");
  reset_usb_boot(0,0);
#endif
  return 0;
}
