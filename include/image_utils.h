#include <opencv2/opencv.hpp>

namespace {

class ImageUtils {
public:
	static bool Compare(const cv::Mat &src1, const cv::Mat &src2)
	{
		if(src1.channels() != src2.channels())
			return false;

		if(src1.rows != src2.rows || src1.cols != src2.cols)
			return false;

		cv::Mat dst(src1.size(), CV_8UC1);
		cv::compare(src1, src2, dst, CV_CMP_EQ);

		if(cv::countNonZero(dst) == 0)
			return true;

		return false;
	}

	static inline uchar SetValue(cv::Mat &im, int x, int y)
	{
		if((x >= 0 && x < im.cols) && (y >= 0 && y < im.rows))
		{
			return im.data[y * im.cols + x];
		}
		return 0;
	}

	static inline void SetValue(cv::Mat &im, int x, int y, uchar value)
	{
		if((x >= 0 && x < im.cols) && (y >= 0 && y < im.rows))
		{
			im.data[y * im.cols + x] = value;
		}
	}
};
}