#include "protocol.h"

size_t protocol_request_auto_id(const uint32_t dst, const uint32_t src,
                                uint8_t *data, const size_t data_size)
{
    return 0;
}

size_t protocol_request_enable_auto_id(const uint32_t dst, const uint32_t src,
                                       uint8_t *data, const size_t data_size,
                                       const bool enable)
{
    return 0;
}

uint32_t protocol_process_auto_id_frame(const uint8_t *data, const size_t data_size,
                                        uint32_t *terminal_address)
{
    return 0;
}

uint32_t protocol_process_enable_auto_id_frame(const uint8_t *data, const size_t data_size,
                                               bool *success)
{
    return 0;
}