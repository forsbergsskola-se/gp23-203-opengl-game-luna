#include "gtest/gtest.h"
#include <iostream>
#include <sstream> 
#include "String.h"


class StringTest : public ::testing::Test{
protected:
    
    void SetUp() override
    {
        maxSize = 100;
        buffer = new char[maxSize + 1];
    }
    
    void TearDown() override
    {
        delete[] buffer;
    }

    int maxSize;
    char* buffer;
};

TEST_F(StringTest, ConstructorAndAppend)
{
    String str(maxSize);
    str.append("Hello");
    str.append("World");
    std::stringstream ss;
    str.print(ss); 
    ASSERT_EQ(ss.str(), "HelloWorld\n");
}

TEST_F(StringTest, AppendLine)
{
    String str(maxSize);
    str.appendLine("Hello");
    std::stringstream ss;
    str.print(ss); (ss.str(), "Hello\n");
}

TEST_F(StringTest, ConcatenationOperator)
{
    String str1(maxSize);
    String str2(maxSize);
    str1.append("Hello");
    str2.append("World");
    String result = str1 + str2;
    std::stringstream ss;
    result.print(ss); 
    ASSERT_EQ(ss.str(), "HelloWorld\n");
}

TEST_F(StringTest, EqualityOperator)
{
    String str1(maxSize);
    String str2(maxSize);
    str1.append("Hello");
    str2.append("Hello");
    ASSERT_EQ(str1, str2);
}

TEST_F(StringTest, LessThanOperator)
{
    String str1(maxSize);
    String str2(maxSize);
    str1.append("Hello");
    str2.append("World");
    ASSERT_LT(str1, str2);
}

TEST_F(StringTest, PrintFunction)
{
    String str(maxSize);
    str.append("Hello");
    str.append("World");
    testing::internal::CaptureStdout();
    str.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "HelloWorld\n");
}

//To unable this main, disable the main in StringClass.cpp

/*int main (int argc, char** argv)
  {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/