#ifndef __ZS_ESP32_SD_CARD__
#define __ZS_ESP32_SD_CARD__
#include <FS.h>
#include <SD_MMC.h>
#include <zs_serial_port_utils.h>

#define PIN_SPI_CS 5 // The ESP32 pin GPIO5

namespace ZS
{
   namespace Esp32
   {
      namespace SdCard
      {
         bool initializeSdCard();
         double getSdCardSizeInGB();
         String getSdCardType();
      }
   }
}

#endif
