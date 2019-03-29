#!/bin/bash
# ***************************************************************************************
#     Dahua Technologies Inc. Copyright (c) 2002-2015
# ***************************************************************************************

START_DIR=`dirname $0`
START_DIR=`cd $START_DIR/..; pwd`

#load GigEDriver
if [ -f $START_DIR/module/GigEDriver/*.ko ]; then
	pushd $START_DIR/module/GigEDriver >>/dev/null
	echo ""
	bash loadDrv.sh
	popd >>/dev/null 
fi

#load U3VDriver
if [ -f $START_DIR/module/USBDriver/*.ko ]; then
	pushd $START_DIR/module/USBDriver >>/dev/null
	echo ""
	bash loadDrv.sh
	popd >>/dev/null 
fi
