#include <FS.h>
#include <SD_MMC.h>
#include <zs_serial_port_utils.h>
#include <zs_esp_32_sd_card.h>

#define PIN_SPI_CS 5 // The ESP32 pin GPIO5

namespace ZS
{
   namespace Esp32
   {

      namespace SdCard
      {
         bool initializeSdCard()
         {

            // pinMode(PIN_SPI_CS, OUTPUT);
            // digitalWrite(PIN_SPI_CS, LOW);

            if (!SD_MMC.begin("/sdcard", true))
            {
               return false;
            }

            return true;
         }

         double getSdCardSizeInGB()
         {
            return (SD_MMC.cardSize() / (1024 * 1024 * 1024));
         }

         String getSdCardType()
         {
            uint8_t cardType = SD_MMC.cardType();

            if (cardType == CARD_NONE)
            {
               ZS::SerialPort::writeErrorToSerialPort("SD card not detected");
            }

            if (cardType == CARD_MMC)
            {
               return ("MMC");
            }
            else if (cardType == CARD_SD)
            {
               return ("SDSC");
            }
            else if (cardType == CARD_SDHC)
            {
               return ("SDHC");
            }
            else
            {
               return ("UNKNOWN");
            }
         }
      }
   }
}

