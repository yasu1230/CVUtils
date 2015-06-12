#!/bin/sh
find include tests -regex ".*\.c\|.*\.cpp\|.*\.h\|.*\.hpp" | xargs python cpplint.py --extensions=h,hpp,c,cpp
