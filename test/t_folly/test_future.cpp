#include <iostream>
#include <gtest/gtest.h>
#include <folly/futures/Future.h>
#include <folly/executors/ThreadedExecutor.h>
#include <folly/Format.h>

class FutureTest : public testing::Test {
};

int32_t foo(int32_t x) {
    std::cout << folly::format("foo({})", x) << "\n";
    return x;
}

TEST_F(FutureTest, basic) {
    folly::ThreadedExecutor executor;
    std::cout << "making Promise" << "\n";
    folly::Promise<int> p;
    folly::Future<int32_t> f = p.getSemiFuture().via(&executor);
    f = std::move(f).thenValue(foo);
    std::cout << "Future chain made" << "\n";

    std::cout << "fulfilling Promise" << "\n";
    int32_t in = 42;
    p.setValue(in); // 触发计算
    int32_t out = std::move(f).get();
    std::cout << folly::format("Promise fulfilled: {}", out) << "\n";

    ASSERT_EQ(in, out);
}
