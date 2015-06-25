// Copyright 2015, yinoue.
// All rights reserved.
#pragma once

#ifndef INCLUDE_IMAGE_UTILS_H_
#define INCLUDE_IMAGE_UTILS_H_

#include <opencv2/opencv.hpp>
#include <vector>

namespace CVUtils {

class ImageUtils {
 public:
  static cv::Rect Trim(const cv::Mat &im) {
    cv::Rect rect;

    int top, bottom, left, right;
    int width, height;

    if (im.empty())
      return rect;

    cv::Mat gray;
    if (im.channels() != 1) {
      cvtColor(im, gray, CV_RGB2GRAY);
    } else {
      gray = im.clone();
    }

    if (cv::countNonZero(gray) == 0)
      return rect;

    width = gray.cols;
    height = gray.rows;

    top = bottom = left = right = -1;

    for (int y = 0; (y < height && top == -1); y++) {
      for (int x = 0; (x < width && top == -1); x++) {
        if (GetValue(gray, x, y) > 0) {
          top = y;
        }
      }
    }

    for (int y = height - 1; (y >= 0 && bottom == -1); y--) {
      for (int x = 0; (x < width && bottom == -1); x++) {
        if (GetValue(gray, x, y) > 0) {
          bottom = y;
        }
      }
    }

    for (int x = 0; (x < width && left == -1); x++) {
      for (int y = 0; (y < height && left == -1); y++) {
        if (GetValue(gray, x, y) > 0) {
          left = x;
        }
      }
    }

    for (int x = width - 1; (x >= 0 && right == -1); x--) {
      for (int y = 0; (y < height && right == -1); y++) {
        if (GetValue(gray, x, y) > 0) {
          right = x;
        }
      }
    }

    return cv::Rect(left, top, abs(right - left), abs(bottom - top));
  }

  static bool IsEqual(const cv::Mat &src1, const cv::Mat &src2) {
    if (src1.empty() && src2.empty())
      return true;

    if (src1.channels() != src2.channels())
      return false;

    if (src1.rows != src2.rows || src1.cols != src2.cols)
      return false;

    cv::Mat diff;
    cv::compare(src1, src2, diff, cv::CMP_NE);
    if (diff.channels() != 1)
      cvtColor(diff, diff, CV_RGB2GRAY);

    if (cv::countNonZero(diff) == 0)
      return true;

    return false;
  }

  static inline uchar GetValue(const cv::Mat &im, int x, int y) {
    if ((x >= 0 && x < im.cols) && (y >= 0 && y < im.rows)) {
      return im.data[y * im.cols + x];
    }
    return 0;
  }

  static inline void SetValue(const cv::Mat &im, int x, int y, uchar value) {
    if ((x >= 0 && x < im.cols) && (y >= 0 && y < im.rows)) {
      im.data[y * im.cols + x] = value;
    }
  }
};

}  // namespace CVUtils
#endif  // INCLUDE_IMAGE_UTILS_H_
