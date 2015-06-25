#include <gtest/gtest.h>

#include "../include/image_utils.h"

using namespace CVUtils;


class IsEqualTest : public ::testing::Test{};

TEST_F(IsEqualTest, is_equal_true)
{
	cv::Mat src = cv::imread("images/test01.png");
	EXPECT_TRUE(ImageUtils::IsEqual(src, src));
}

TEST_F(IsEqualTest, is_equal_false)
{
	cv::Mat src1 = cv::imread("images/test01.png");
	cv::Mat src2 = cv::imread("images/test02.png");
	EXPECT_FALSE(ImageUtils::IsEqual(src1, src2));
}

TEST_F(IsEqualTest, is_equal_empty)
{
	cv::Mat src1;
	cv::Mat src2;
	EXPECT_TRUE(ImageUtils::IsEqual(src1, src2));
}

TEST_F(IsEqualTest, is_equal_differnt_channel)
{
	cv::Mat src1 = cv::Mat::zeros(cv::Size(64, 64), CV_8UC3);
	cv::Mat src2 = cv::Mat::zeros(cv::Size(64, 64), CV_8UC1);

	EXPECT_FALSE(ImageUtils::IsEqual(src1, src2));
}

TEST_F(IsEqualTest, is_equal_differnt_rows)
{
	cv::Mat src1 = cv::Mat::zeros(cv::Size(64, 64), CV_8UC1);
	cv::Mat src2 = cv::Mat::zeros(cv::Size(32, 64), CV_8UC1);
	EXPECT_FALSE(ImageUtils::IsEqual(src1, src2));
}

TEST_F(IsEqualTest, is_equal_differnt_cols)
{
	cv::Mat src1 = cv::Mat::zeros(cv::Size(64, 64), CV_8UC1);
	cv::Mat src2 = cv::Mat::zeros(cv::Size(64, 32), CV_8UC1);
	EXPECT_FALSE(ImageUtils::IsEqual(src1, src2));
}
