#include <gtest/gtest.h>

#include "../include/image_utils.h"

using namespace CVUtils;


class GetSetValueTest : public ::testing::Test{};

TEST_F(GetSetValueTest, get_value)
{
	cv::Mat src = cv::Mat::zeros(cv::Size(32, 32), CV_8UC1);

	cv::Mat dst = src.clone();

	for(int x = -1; x <= dst.rows; x++)
	{
		for(int y = -1; y <= dst.cols; y++)
		{
			EXPECT_TRUE(ImageUtils::GetValue(src, x, y) == 0);
		}
	}

}

TEST_F(GetSetValueTest, set_value)
{
	cv::Mat src = cv::Mat::zeros(cv::Size(32, 32), CV_8UC1);

	cv::Mat dst = src.clone();

	for(int x = 0; x < src.rows; x++)
	{
		for(int y = 0; y < src.cols; y++)
		{
			ImageUtils::SetValue(src, x, y, 128);
		}
	}

	EXPECT_TRUE(cv::countNonZero(src) == (src.rows * src.cols));
}

