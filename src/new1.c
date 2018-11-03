#include "board.h"
#include "fsl_lptmr_driver.h"
#include "fsl_debug_console.h"

void new1(void)
{
	 uint8_t receiveBuff;
     // Main routine that simply echoes received characters forever
	 PRINTF("\r\nNEW CHAR!\r\n\r\n");
     // First, get character
     receiveBuff = GETCHAR();

     // Now echo the received character
     PUTCHAR(receiveBuff);
}
