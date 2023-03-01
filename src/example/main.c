#include "main.h"

int main()
{
    e2t_telemetry_map telemetry_map;

    while (e2t_true)
    {
        Sleep(1000);
        system("cls");

        if(!e2t_get_telemetry_data(&telemetry_map))
        {
            printf("Telemetry data is not available now.\n");
            continue;
        }

        if(telemetry_map.paused)
            printf("[In pause]");
        
        printf("Engine is %s.\n", telemetry_map.tel_rev1.engine_enabled ? "enabled" : "disabled");
        printf("Truck speed: %f.\n", telemetry_map.tel_rev1.speed);
    }
    
    return 0;
}