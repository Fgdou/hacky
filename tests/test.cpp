//
// Created by fgdou on 14/05/2021.
//

#include <gtest/gtest.h>

int main(int arc, char** arv){
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

TEST(test, test){
    ASSERT_TRUE(true);
}