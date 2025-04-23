# Technical Test for Embedded Software Engineer

## Objective
Develop a C program for a Controller that communicates with up to 24 Terminals using a half-duplex RS-485 communication channel. The goal is to implement a mechanism to automatically identify all connected Terminals by interacting with the available communication protocol.

**Your task is to implement a function in C (C99 standard) that auto-identifies all connected Terminals and returns a list of their unique 32-bit addresses.**

## System Description
- The system is a distributed system with a Controller (Master) and up to 24 Terminals (Slaves).
- Communication occurs over a wired RS-485 channel in half-duplex mode, where only one device (Controller or Terminal) can send data at a time.
- The Controller initiates communication with Terminals, which respond only when addressed.
- Each Terminal has a unique 32-bit physical address assigned during manufacturing.
- The physical access to RS-485 is abstracted via the rs485.h library.
- The protocol used for communication between Controller and Terminals is abstracted via the protocol.h library.

### Protocol Information:
1.	Message Format:
    - All frames exchanged include a header with 32-bit source and destination addresses.
    - The Controller can send broadcast messages using the reserved broadcast address 0xFFFFFFFF. Terminals do not reply to broadcast messages unless explicitly specified.
2.	Commands:
    - Auto Identification (Auto ID):
        - When a Terminal receives this command, it calculates a random delay of up to 2000 milliseconds before replying with its unique address.
        - The Terminals can reply even if the command is sent using the broadcast address unless Auto ID has been disabled on the Terminal.
    - Enable/Disable Auto Identification:
        - This command can enable or disable the Auto ID feature on a Terminal.
        - This command can be broadcasted to all Terminals, but they do not reply to broadcasted Enable/Disable commands.
3.	Reply Handling:
    - Auto ID Reply:
        - The Controller must be able to process replies from multiple Terminals in response to an Auto ID command, extracting each Terminal's unique 32-bit address.
    - Enable/Disable Auto ID Reply:
        - The reply frame indicates whether the command was successfully processed (only for specific, non-broadcast commands).

## Test Deliverables:
As a support to validate the test, a CMake project is provided that includes a dummy implementation of the RS-485 and the protocol libraries. Please read the README.md file to learn how to build the project.

### Task 1: Auto Identification Function
- Provide detailed documentation explaining your approach, that describes how the communication between the Controller and the Terminals works, and how collisions or communication failures are handled.
- Implement the function auto_identify_terminals, defined in the auto_id.h header file.
- The provided code must build properly in the provided project.

### Task 2: Optimizing Identification Time
- You should minimize the time required to identify all Terminals.
- Outline how your solution reduces the identification time.

### Bonus:
- Provide unit tests of the autoid.c module.
- Fix any bug or memory leak that is found in the provided code.

## Requirements:
1.	Use the provided rs485.h and protocol.h libraries to access the RS-485 communication channel and to handle the protocol.
2.	Avoid low-level initializations like UART or GPIO setup; these are already done.
3.	The protocol library abstracts the frame encapsulation and decapsulation.
4.	Your code should work with a maximum of 24 Terminals.

## Evaluation Criteria:
1.	Correctness: Does the function correctly identify all connected Terminals?
2.	Efficiency: Is the identification process optimized to minimize time (e.g., by disabling Auto ID on already identified Terminals)? No need to implement but can you suggest ways to optimize the process?
3.	Code Quality: Is the code clean, modular, and well-documented?
4.	Handling of Edge Cases: Does the code handle potential communication errors, timeouts, or collisions properly?
5.	Scalable: Can you improve the code to make work for a different maximum number of terminals?
6.	Unit Testing (Bonus): Providing unit tests for your solution will significantly improve your rating. Document unit tests that simulate various scenarios (e.g., a different number of connected Terminals, communication timeouts, collisions). You can use the provided test infrastructure based on Ceedling.

## Submission:
- Submit your solution:
    - As a repository branch (prefered):
        - Include your source code
        - Documentation
        - (Optional) unit tests that will be executed on every push.
    - In a `.zip` file containing:
        - C source code.
        - Documentation.
        - (Optional) Unit tests.
