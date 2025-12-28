#include <gtest/gtest.h>

int main(int argc, char **argv) {
    // something init...
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    // something distory...
}
