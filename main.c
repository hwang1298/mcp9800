#include <avr/io.h>
#include "mcp9800.h"
int main (void)
{
    char buf[32];

    //init MCP9800 sensor
    mcp_init();
    mcp_set_adc_resolution(MCP_ADC_RES_12);
    mcp_set_power_mode(MCP_POWER_UP);    
    
    while (1) {
        float temp = mcp_read_temp_float();
        sprintf(buf, "tmep: %.4f\n", temp);
    }
    return 0;
}
