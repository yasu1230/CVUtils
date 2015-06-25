#!/bin/sh
find include -regex ".*\.c\|.*\.cpp\|.*\.h\|.*\.hpp" | xargs python cpplint.py --extensions=h,hpp,c,cpp --filter=-runtime/references
