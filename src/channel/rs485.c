#include "rs485.h"

/**
 * @brief Send a byte stream through the RS-485 Channel
 *
 * @param [in] data Byte array that stores the data to be sent
 * through the RS-485 channel
 * @param [in] data_size Amount of bytes of data stored in "data"
 * @return -1 If the operation fails, or the number of bytes
 * actually sent.
 */
int32_t rs_485_send(const uint8_t *data, const size_t data_size)
{
    return data_size;
}

/**
 * @brief Receives from the RS-485 Channel
 *
 * @param [out] data Byte array where the function will store the
 * bytes receieved by the channel
 * @param [in] data_size Amount of bytes the the "data" parameter
 * can hold
 * @param timeout Time expressed in miliseconds that the function
 * will wait for data to be received.
 * @return -1 If the operation fails, or the number of bytes
 * actually received.
 */
int32_t rs_485_receive(uint8_t *data, const size_t data_size, const const uint32_t timeout)
{
    return 0;
}