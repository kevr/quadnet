#include <gtest/internal/gtest-port.h>
#define main _main
#include "main.cpp"
#undef main

#include <gtest/gtest.h>

// Create argv + argc based on optional arguments passed.
// These can be directly passed to our main function.
//
// Ex:
//   MAKE_ARGV();
//   _main(argc, argv);
//
#define MAKE_ARGV(...)                                                        \
    const char *argv[] = { PROJECT_NAME.data(), __VA_ARGS__ };                \
    int argc = sizeof(argv) / sizeof(argv[0]);

TEST(main, works)
{
    testing::internal::CaptureStdout();

    MAKE_ARGV();
    EXPECT_EQ(_main(argc, argv), 0);

    auto output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, PROJECT_NAME + " - " + PROJECT_DESC + "\n");
}

TEST(main, takes_no_arguments)
{
    testing::internal::CaptureStderr();

    MAKE_ARGV("test");
    EXPECT_EQ(_main(argc, argv), 1);

    auto output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "error: quadnet takes no arguments\n");
}
