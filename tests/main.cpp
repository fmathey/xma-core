#define XMA_IMPLEMENTATION

#include <XMA/Core.hpp>

int main()
{
    XMA_TEST("Should be equal", []() {
        XMA_ASSERT_EQUAL(1, 1);
        XMA_ASSERT_THROW([]() { XMA_ASSERT_EQUAL(2,3); });
    });

    XMA_TEST("Should not be equal", []() {
        XMA_ASSERT_NOT_EQUAL(1, 2);
        XMA_ASSERT_THROW([]() { XMA_ASSERT_NOT_EQUAL(5,5); });
    });

    XMA_TEST("Should be higher", []() {
        XMA_ASSERT_HIGHER(4, 2);
        XMA_ASSERT_HIGHER(100, 20);
        XMA_ASSERT_THROW([]() { XMA_ASSERT_HIGHER(2,3); });
    });

    XMA_TEST("Should be higher or equal", []() {
        XMA_ASSERT_HIGHER_OR_EQUAL(2, 2);
        XMA_ASSERT_HIGHER_OR_EQUAL(1200, 1200);
        XMA_ASSERT_HIGHER_OR_EQUAL(1200, 1199);
        XMA_ASSERT_HIGHER_OR_EQUAL(100, 90);
        XMA_ASSERT_THROW([]() { XMA_ASSERT_HIGHER_OR_EQUAL(100,300); });
    });

    XMA_TEST("Should be lower", []() {
        XMA_ASSERT_LOWER(1, 2);
        XMA_ASSERT_LOWER(4, 5);
        XMA_ASSERT_THROW([]() { XMA_ASSERT_LOWER(4,3); });
    });

    XMA_TEST("Should be lower or equal", []() {
        XMA_ASSERT_LOWER_OR_EQUAL(2, 2);
        XMA_ASSERT_LOWER_OR_EQUAL(500, 1200);
        XMA_ASSERT_LOWER_OR_EQUAL(9000, 10000);
        XMA_ASSERT_LOWER_OR_EQUAL(12059, 12059);
        XMA_ASSERT_THROW([]() { XMA_ASSERT_LOWER_OR_EQUAL(500,300); });
    });

    XMA_TEST("Should throw", []() {
        XMA_ASSERT_THROW([]() { throw 1; });
        XMA_ASSERT_THROW([]() { throw std::exception(); });
        XMA_ASSERT_THROW([]() { throw "error"; });
    });

    XMA_TEST("Should not throw", []() {
        XMA_ASSERT_NOT_THROW([]() { });
    });

    XMA_TEST("Should throw integer", []() {
        XMA_ASSERT_THROW_TYPE([]() { throw 1; }, int);
    });

    XMA_TEST("Should throw std::exception", []() {
        XMA_ASSERT_THROW_TYPE([]() { throw std::exception(); }, std::exception);
        XMA_ASSERT_THROW_TYPE([]() { throw std::logic_error("Hello world"); }, std::exception);
        XMA_ASSERT_THROW_TYPE([]() { throw std::runtime_error("Hello world"); }, std::exception);
    });

    XMA_TEST("Should throw std::logic_error", []() {
        XMA_ASSERT_THROW_TYPE([]() { throw std::logic_error("Hello world"); }, std::logic_error);
        XMA_ASSERT_THROW_TYPE([]() { throw std::logic_error("Hello world"); }, std::exception);
    });

    XMA_TEST("Should throw std::string", []() {
        XMA_ASSERT_THROW_TYPE([]() { throw std::string("Hello"); }, std::string);
    });

    XMA_TEST("Should not throw std::exception", []() {
        XMA_ASSERT_NOT_THROW_TYPE([]() { throw 2; }, std::exception);
        XMA_ASSERT_NOT_THROW_TYPE([]() { throw std::string("Hello"); }, std::exception);
    });

    XMA_TEST("Should not throw int", []() {
        XMA_ASSERT_NOT_THROW_TYPE([]() { throw std::exception(); }, int);
        XMA_ASSERT_NOT_THROW_TYPE([]() { throw std::string("Hello"); }, int);
    });

    XMA_TEST("Should bootstrap function return 0", []() {
        int increment = 1;
        XMA::Core::bootstrap([&]() { increment++; });
        XMA_ASSERT_EQUAL(increment, 2);
    });

    XMA_TEST("Should bootstrap function called", []() {
        XMA_ASSERT(XMA::Core::bootstrap([]() {}) == 0);
    });

    XMA_TEST("Should bootstrap function not throw", []() {
        int result = -100;
        XMA_ASSERT_NOT_THROW([&]() { result = XMA::Core::bootstrap([&]() { throw 1; }, false); });
        XMA_ASSERT_EQUAL(result, 0);
    });

    return 0;
}