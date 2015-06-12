#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_lib.hpp>
#include "../include/image_utils.h"

//#pragma comment(lib,"gtestd.lib")
//#pragma comment(lib,"libcpmtd.lib")

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return ret;
}

TEST(CompareTest, compare_true)
{
	cv::Mat src = cv::imread("images/test01.png");
	EXPECT_TRUE(ImageUtils::Compare(src, src));
}

TEST(CompareTest, compare_false)
{
	cv::Mat src1 = cv::imread("images/test01.png");
	cv::Mat src2 = cv::imread("images/test02.png");
	EXPECT_TRUE(ImageUtils::Compare(src1, src2));
}