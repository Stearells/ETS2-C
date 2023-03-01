#include "ets2telemetry.h"

e2t_bool e2t_get_telemetry_data(e2t_telemetry_map *map)
{
    if (map == e2t_nullptr)
        return e2t_false;
    
    HANDLE h_mapped_file = OpenFileMapping(
                            FILE_MAP_READ, 
                            e2t_false, 
                            MAPPED_FILENAME);
    if (!h_mapped_file)
        return e2t_false;
    
    void* mapped_file_memory = MapViewOfFile(
                                h_mapped_file, 
                                FILE_MAP_READ, 
                                0, 
                                0, 
                                sizeof(e2t_telemetry_map));

    if(mapped_file_memory != e2t_nullptr)
    {
        memcpy(map, mapped_file_memory, sizeof(e2t_telemetry_map));
        UnmapViewOfFile(mapped_file_memory);
        CloseHandle(h_mapped_file);
        return e2t_true;
    }

    CloseHandle(h_mapped_file);
    return e2t_false;
}