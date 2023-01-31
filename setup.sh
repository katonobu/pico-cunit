#!/bin/bash
if [ -d CUnit-2.1-3 ];then
    echo 'CUnit-2.1-3 exist, skip downloading'
else
    wget https://sourceforge.net/projects/cunit/files/CUnit/2.1-3/CUnit-2.1-3.tar.bz2
    tar jxf CUnit-2.1-3.tar.bz2
    rm CUnit-2.1-3.tar.bz2
fi
cat CUnit-2.1-3/CUnit/Headers/CUnit.h.in | sed -e s/@VERSION@/2.1/g | sed -e s/@RELEASE@/3/g > CUnit-2.1-3/CUnit/Headers/CUnit.h
echo 'setup CUnit-2.1-3 finished'




