#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define PROTOCOL_BROADCAST_ADDRESS 0xFFFFFFFF

/**
 * @brief Create an "Auto ID" command frame, ready to be sent.
 *
 * It writes to memory the data representing an Auto Identification
 * frame, to be sento to the terminals.
 * @param [in] dst Destination physical address. Use PROTOCOL_BROADCAST_ADDRESS
 * to send the command to every terminal.
 * @param [in] src Controller's physical address.
 * @param [out] data Byte array where the function will store the
 * frame.
 * @param [in] data_size Amount of bytes the the "data" parameter
 * can hold
 * @return Number of bytes written to the data buffer.
 */
size_t protocol_request_auto_id(const uint32_t dst, const uint32_t src,
								uint8_t *data, const size_t data_size) __attribute__((nonnull(3)));

/**
 * @brief Create a "Enable/Disable Auto ID" command frame, ready to be sent.
 *
 * It writes to memory the data representing an enable/disable
 * Auto Identification frame, to be sento to the terminals. When a terminal
 * has Auto ID enabled it will reply to the Auto ID command.
 * @param [in] dst Destination physical address. Use PROTOCOL_BROADCAST_ADDRESS
 * to send the command to every terminal.
 * @param [in] src Controller's physical address.
 * @param [out] data Byte array where the function will store the
 * frame.
 * @param [in] data_size Amount of bytes the the "data" parameter
 * can hold
 * @param [in] enable If true the Terminal/s receiving this command will
 * enable the Auto ID functionality. If false they will disable it.
 * @return Number of bytes written to the data buffer.
 */
size_t protocol_request_enable_auto_id(const uint32_t dst, const uint32_t src,
									   uint8_t *data, const size_t data_size,
									   const bool enable) __attribute__((nonnull(3)));

/**
 * @brief Process an "Auto ID" reply frame received from a Terminal.
 *
 * It processes a buffer of data received from the Terminals, looking for a
 * frame that holds the reply to an "Auto ID" command.
 * @param [in] data Buffer of data received from the Terminals.
 * @param [in] data_size Amount of bytes the the "data" parameter
 * @param [out] terminal_address. If a valid frame with a reply is found
 * in the buffer, the function will write in this parameter the unique address
 * of the device replying.
 * @return Index of the next byte after a valid Auto ID frame has been found, or
 * -1 if no frame was found.
 */
uint32_t protocol_process_auto_id_frame(const uint8_t *data, const size_t data_size,
										uint32_t *terminal_address) __attribute__((nonnull(1)));

/**
 * @brief Process the reply frame received from a Terminal to the enable
 * or disable Auto ID command.
 *
 * It processes a buffer of data received from the Terminals, looking for a
 * frame that holds the result to an enable/disable Auto ID command.
 * @param [in] data Buffer of data received from the Terminal.
 * @param [in] data_size Amount of bytes the the "data" parameter.
 * @param [out] bool. If a valid frame with a reply is found in the buffer,
 * the function will write in this parameter the command result.
 * @return Index of the next byte after a valid Auto ID frame has been found, or
 * -1 if no frame was found.
 */
uint32_t protocol_process_enable_auto_id_frame(const uint8_t *data, const size_t data_size,
											   bool *success) __attribute__((nonnull(1)));

#endif // __PROTOCOL_H__