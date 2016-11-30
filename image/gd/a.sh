#!/bin/bash - 
#===============================================================================
#
#          FILE: a.sh
# 
#         USAGE: ./a.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2016年09月12日 04:08
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
for i in {1..10};do ./a.out ${i}0 test1/test.jpg test1/test.${i}.webp;done
for i in {1..10};do ./a.out ${i}0 test2/test.jpg test2/test.${i}.webp;done
for i in {1..10};do ./a.out ${i}0 test3/test.jpg test3/test.${i}.webp;done
for i in {1..10};do ./a.out ${i}0 test4/test.jpg test4/test.${i}.webp;done

