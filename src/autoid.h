#ifndef __AUTOID_H__
#define __AUTOID_H__
#include <stdint.h>

/**
 * @brief Auto-identifies all connected Terminals.
 *
 * This function sends a broadcast Auto ID command to all connected Terminals.
 * It collects the unique 32-bit addresses of the Terminals that respond, storing them in an array.
 *
 * @param[in] source_address Source address of the Controller.
 * @param[out] terminals_list Pointer to a dynamically allocated array of 32-bit Terminal addresses.
 *         The caller is responsible for freeing this memory.
 * @return Integer where the number of identified Terminals will be stored. -1 if the operation fails.
 */
int32_t auto_identify_terminals(const uint32_t source_address, uint32_t **terminals_list);

#endif // __AUTOID_H__