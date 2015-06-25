#include <gtest/gtest.h>

#include "is_equal_test.h"
#include "get_set_value_test.h"
#include "trim_test.h"

#ifdef _MSC_VER
#include <opencv2/opencv_lib.hpp>
#endif

//#pragma comment(lib,"gtestd.lib")
//#pragma comment(lib,"libcpmtd.lib")

using namespace CVUtils;

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return ret;
}
