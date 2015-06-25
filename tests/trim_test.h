#include <gtest/gtest.h>

#include "../include/image_utils.h"

using namespace CVUtils;

class TrimTest : public ::testing::Test{};

TEST_F(TrimTest, empty)
{
	cv::Mat src;
	cv::Rect rect = ImageUtils::Trim(src);

	EXPECT_TRUE(rect.x == 0);
	EXPECT_TRUE(rect.y == 0);
	EXPECT_TRUE(rect.width == 0);
	EXPECT_TRUE(rect.height == 0);

}

TEST_F(TrimTest, zeros)
{
	cv::Mat src = cv::Mat::zeros(cv::Size(32, 32), CV_8UC1);
	cv::Rect rect = ImageUtils::Trim(src);

	EXPECT_TRUE(rect.x == 0);
	EXPECT_TRUE(rect.y == 0);
	EXPECT_TRUE(rect.width == 0);
	EXPECT_TRUE(rect.height == 0);

}

TEST_F(TrimTest, trim)
{
	cv::Mat src = cv::Mat::zeros(cv::Size(33, 33), CV_8UC1);

	cv::circle(src, cv::Point(16, 16), 11, cv::Scalar(255), 1);

	cv::Rect rect = ImageUtils::Trim(src);

	EXPECT_TRUE(rect.x == 5);
	EXPECT_TRUE(rect.y == 5);
	EXPECT_TRUE(rect.width == 22);
	EXPECT_TRUE(rect.height == 22);

}

