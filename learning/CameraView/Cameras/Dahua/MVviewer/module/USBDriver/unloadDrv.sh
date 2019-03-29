#!/bin/bash

DriverName=mvUniversalProForU3V

DriverList=`cat /proc/modules | grep u3v_drv`
if [[ $DriverList =~ "u3v_drv" ]]; then	
	DriverName=u3v_drv
fi

# Unload the module
echo "Unloading Universal U3V..."
rmmod $DriverName.ko || exit 1

KERNEL_VER=`uname -r`
V4L2_MODULE_ROOT_PATH=/lib/modules/$KERNEL_VER/kernel/drivers/media
V4L2_MODULE_PATH_1=$V4L2_MODULE_ROOT_PATH/video
V4L2_MODULE_PATH_2=$V4L2_MODULE_ROOT_PATH/v4l2-core

if [ -f "$V4L2_MODULE_PATH_1/videodev.ko" ];then
	echo "Unloading $V4L2_MODULE_PATH_1/videodev.ko..."
	rmmod $V4L2_MODULE_PATH_1/videodev.ko
if [ -f "$V4L2_MODULE_PATH_1/v4l2-compat-ioctl32.ko" ];then
	echo "Unloading $V4L2_MODULE_PATH_1/v4l2-compat-ioctl32.ko..."
	rmmod $V4L2_MODULE_PATH_1/v4l2-compat-ioctl32.ko
fi
elif [ -f "$V4L2_MODULE_PATH_2/videodev.ko" ];then
	echo "Unloading $V4L2_MODULE_PATH_2/videodev.ko..."
	rmmod $V4L2_MODULE_PATH_2/videodev.ko

if [ -f "$V4L2_MODULE_ROOT_PATH/media.ko" ];then
	echo "Unloading $V4L2_MODULE_ROOT_PATH/media.ko..."
	rmmod $V4L2_MODULE_ROOT_PATH/media.ko
fi	

else
	echo "no v4l2 module found!"
fi

echo "Unloading Universal U3V drivers successfully!"
