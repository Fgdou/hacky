//
// Created by fgdou on 14/05/2021.
//

#include "BigInt.h"

TEST(BitInt, simpleoperations){
    BigInt l1("111");
    BigInt l2 = "123";
    BigInt l3 = "9";

    ASSERT_EQ("234", (std::string)(l1 + l2));
    ASSERT_EQ("234", (std::string)(l2 + l1));
    ASSERT_EQ("120", (std::string)(l1 + l3));
    ASSERT_EQ("10", (std::string)(l3 + 1));
    ASSERT_EQ("12", (std::string)(l2 - l1));
    ASSERT_EQ("-12", (std::string)(l1 - l2));
    ASSERT_EQ("-9", (std::string)(BigInt(0) - l3));

    //ASSERT_STREQ("13653", l1 * l2);
    //ASSERT_STREQ("13653", l2 * l1);
}