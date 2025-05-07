# Technical Test for Embedded Software Engineer

## Objective
The goal of this coding test is to implement a C module called *autoid* that allows a controller (master) to automatically discover up to 24 terminals (slaves) connected to it over an RS-485 half-duplex bus. The module must implement a discovery mechanism that queries the bus and retrieves a list of the unique addresses of all connected terminals. It does not assign addresses, each terminal already has a unique, preconfigured address. The module must handle communication over the RS-485 bus, and protocol encapsulation by using a provided library called *channel*, and ensuure reliable detection of all active terminals, and return a complete list of discovered addresses.

**Your task is to implement a function in C (C99 standard) that identifies all connected Terminals and returns a list of their unique 32-bit addresses.**

## System Description
- The system is a distributed system with a Controller and up to 24 Terminals.
- Communication occurs over a wired RS-485 channel in half-duplex mode, where only one device (Controller or Terminal) can send data at a time.
- The Controller initiates communication with Terminals, which respond only when addressed.
- Each Terminal has a unique 32-bit physical address assigned during manufacturing.
- The physical access to RS-485 is abstracted via the rs485.h interface, part of the *channel* library. Assume that the serial port works correctly.
- The protocol used for communication between Controller and Terminals is abstracted via the protocol.h interface, part of the *channel* library.
- After boot all the terminals have auto identificattion enabled, meaning they will reply to a request auto id frame. Auto identificattion can be disabled in a terminal, then it will not reply to a request auto id frame.
- For the sake of simplicity consider that there are no external constraints to the execution, like a watchdog, or other tasks running in parallel. You have full control of the processor/memory.
- Avoid low-level initialization like UART or GPIO setup; assume this is already done.

### Bus:

**Note:** The bus functionality **must not** be implemented. If you want to test your code use the unit tests mocks already provided.

- There is a function to send through the RS-485 bus.

```
int32_t rs_485_send(const uint8_t *data, const size_t data_size) __attribute__((nonnull(1)));
```

- There is a function to receive from the RS-485 bus.

```
int32_t rs_485_receive(uint8_t *data, const size_t data_size, const const uint32_t timeout) __attribute__((nonnull(1)));
```

### Protocol:

**Note:** The protocol functionality **must not** be implemented. If you want to test your code use the unit tests mocks already provided.

Message Format:
 - All frames exchanged include a header that embeds two 32-bit addresses for source and destination.
 - The Controller can send broadcast messages using the reserved broadcast address 0xFFFFFFFF, that all the terminals must process. Terminals do not reply to broadcast messages unless explicitly specified.
 - The largest frame is 32 bytes.

#### Commands:

##### Auto Identification (Auto ID):

```
size_t protocol_request_auto_id(const uint32_t dst, const uint32_t src,
                                            uint8_t *data, const size_t data_size) __attribute__((nonnull(3)));
```

- if *dst* is the broadcast address all the terminals that have enabled auto identification must calculate a random delay of up to 2000 milliseconds before replying with its unique address.
- if *dst* is an speciic terminal address only that terminal, if auto identification is enabled, must reply inmediately with its unique address.
- The returned frame may include valid replies from terminals, but also collisions. Use the following function to retrieve valid replies:

```
uint32_t protocol_process_auto_id_frame(const uint8_t *data, const size_t data_size,
										uint32_t *terminal_address) __attribute__((nonnull(1)));
```

##### Enable/Disable Auto Identification:

```
size_t protocol_request_enable_auto_id(const uint32_t dst, const uint32_t src,
									   uint8_t *data, const size_t data_size,
									   const bool enable) __attribute__((nonnull(3)));
```

- This command can enable or disable the Auto ID feature on a Terminal.
- if *dst* is the broadcast address all the terminals must execute the command but do not reply.
- if *dst* is an speciic terminal address only that terminal must execute the command and reply. A valid reply can be parsed with the following function:

```
uint32_t protocol_process_enable_auto_id_frame(const uint8_t *data, const size_t data_size,
											   bool *success) __attribute__((nonnull(1)));
```

## Test Deliverables:
As a support to validate the test, a CMake project is provided that includes a dummy implementation of the RS-485 and the protocol libraries. Please read the README.md file to learn how to build the project.

### Main task: Auto Identification Function
- Implement the function *auto_identify_terminals*, defined in the autoid.h header file.
- It must loop until all the connected terminals have been identified, and then return a list of the unique addresses of those terminals.
- Provide detailed documentation explaining your approach, that describes the function execution flow.
- The resulting code must build properly in the provided project.

### Bonus 1: Optimizing Identification Time
- You should minimize the time required to identify all Terminals.
- Outline how your solution reduces the identification time.

### Bonus 2:
- Provide unit tests of the autoid.c module.
- Fix any bug or memory leak that is found in the provided code.

## Evaluation Criteria:
1.	Correctness: Does the function correctly identify all connected Terminals?
2.	Code Quality: Is the code clean, modular, and well-documented?
3.	Handling of Edge Cases: Does the code handle potential communication errors, timeouts, or collisions properly?
4.	Scalable: Can you improve the code to make work for a different maximum number of terminals?
5.	Efficiency (Bonus): Is the identification process optimized to minimize time.
6.	Unit Testing (Bonus): Providing unit tests for your solution will significantly improve your rating. Document unit tests that simulate various scenarios (e.g., a different number of connected Terminals, communication timeouts, collisions). You can use the provided test infrastructure based on Ceedling.

## Submission:
- You can push your changes straight to the main branch of the provided repository, or create a custom branch if you like.
- Add any files that you may consider as code or documentation.
