#ifdef TEST
#include "unity.h"
#include "mock_rs485.h"
#include "mock_protocol.h"
#include "autoid.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_auto_identify_terminals__dummy(void)
{

    TEST_ASSERT_EQUAL(0, auto_identify_terminals(0, NULL));
}

#endif // TEST