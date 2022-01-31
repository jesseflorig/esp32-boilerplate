/* ESP32 Boilerplate

Based heavily on the ESP IDF Hello World Example

Refactored for code and output clarity.

*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

void app_main(void)
{
    /* Print greeting */
    printf("\nHello world from ESP32 Boilerplate!\n\n");

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    printf("Chip:\t\t%s, rev %d\n", 
        CONFIG_IDF_TARGET, 
        chip_info.revision);
    printf("Core%s:\t\t%d\n", 
        (chip_info.cores != 1) ? "s" : "",
        chip_info.cores);
    printf("Wireless:\tWiFi%s%s\n", 
        (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
        (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    printf("Memory:\t\t%dMB %s flash\n", 
        spi_flash_get_chip_size() / (1024 * 1024),
        (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
    printf("Min heap:\t%d bytes\n\n", 
        esp_get_minimum_free_heap_size());

    /* Print restart information */
    for (int i = 10; i >= 0; i--) {
        if(i==10 || i==5){
            printf("Restarting in %d seconds...\n", i);
        }
        if(i==0){
            printf("Restarting...\n");
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    /* Clear monitor and restart  */
    fflush(stdout);
    esp_restart();
}