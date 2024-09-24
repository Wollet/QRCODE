#ifndef __QRENCODE_MAIN_H__
#define __QRENCODE_MAIN_H__

#include <stdlib.h>
#include <stdint.h>
#include "string.h"
#include "qr_encode.h"
#include "qr_consts.h"
#include "lcd.h"

void QRGenerator(char *input);

void displayQRCode(int side, uint8_t *bitdata);

#endif

