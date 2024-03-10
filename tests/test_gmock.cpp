#include <gtest/gtest.h>
#include <gmock/gmock.h>

// Interface definition
class MyInterface {
public:
    virtual ~MyInterface() = default;
    virtual int getValue() const = 0;
};

// Class under test
class MyClass {
public:
    explicit MyClass(MyInterface* interface) : interface_(interface) {}
    int doSomething() {
        int value = interface_->getValue();
        // Perform some operation with the value
        return value * 2;
    }

private:
    MyInterface* interface_;
};

// Mock class definition
class MockMyInterface : public MyInterface {
public:
    MOCK_METHOD(int, getValue, (), (const, override));
};

// Test case
TEST(MyClassTest, DoSomethingTest) {
    MockMyInterface mockInterface;
    EXPECT_CALL(mockInterface, getValue())
        .WillOnce(::testing::Return(42));

    MyClass myClass(&mockInterface);
    int result = myClass.doSomething();
    EXPECT_EQ(result, 84);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}