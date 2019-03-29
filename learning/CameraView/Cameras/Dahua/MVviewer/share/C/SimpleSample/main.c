/// \file
/// \~chinese
/// \brief 拉流处理范例
/// \example grab.c
/// \~english
/// \brief stream grabbing sample
/// \example grab.c

/************************************************************************/
/* This Demo show how to use GenICam API(C) to write a simple code.
   Please make sure the camera and PC are in the same network(IP address is correctly seted) before run the demo. */
   
/* 本Demo为简单演示SDK的使用，没有附加修改相机IP的代码，在运行之前，请使
	用相机客户端修改相机IP地址的网段与主机的网段一致                 */
/************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pthread.h"
#include "GenICam/CAPI/SDK.h"

#define INFINITE            0xFFFFFFFF  // Infinite timeout
#define CREATE_SUSPENDED    0x00000004
GENICAM_StreamSource *pStreamSource = NULL;

static int32_t GENICAM_connect(GENICAM_Camera *pGetCamera)
{
	int32_t isConnectSuccess;

	isConnectSuccess = pGetCamera->connect(pGetCamera, accessPermissionControl);

	if( isConnectSuccess != 0)
	{
		printf("connect cameral failed.\n");
		return -1;
	}
	
	return 0;
}

static int32_t GENICAM_CreateStreamSource(GENICAM_Camera *pGetCamera, GENICAM_StreamSource **ppStreamSource)
{
	int32_t isCreateStreamSource;
	GENICAM_StreamSourceInfo stStreamSourceInfo;


	stStreamSourceInfo.channelId = 0;
	stStreamSourceInfo.pCamera = pGetCamera;

	isCreateStreamSource = GENICAM_createStreamSource(&stStreamSourceInfo, ppStreamSource);
	
	if( isCreateStreamSource != 0)
	{
		printf("create stream obj  fail.\r\n");
		return -1;
	}
	
	return 0;
}

static int32_t GENICAM_startGrabbing(GENICAM_StreamSource *pStreamSource)
{
	int32_t isStartGrabbingSuccess;
	GENICAM_EGrabStrategy eGrabStrategy;

	eGrabStrategy = grabStrartegySequential;
	isStartGrabbingSuccess = pStreamSource->startGrabbing(pStreamSource, 0, eGrabStrategy);

	if( isStartGrabbingSuccess != 0)
	{
		printf("StartGrabbing  fail.\n");
		return -1;
	}
	
	return 0;
}

static int32_t GENICAM_stopGrabbing(GENICAM_StreamSource *pStreamSource)
{
	int32_t isStopGrabbingSuccess;

	isStopGrabbingSuccess = pStreamSource->stopGrabbing(pStreamSource);
	if( isStopGrabbingSuccess != 0)
	{
		printf("StopGrabbing  fail.\n");
		return -1;
	}
	
	return 0;
}

static int32_t modifyCamralExposureTime(GENICAM_Camera *pGetCamera)
{
	int32_t isExposureTimeSuccess;
	GENICAM_DoubleNode doubleNode;
	double exposureTimeValue;
	GENICAM_AcquisitionControl *pAcquisitionCtrl = NULL;
	GENICAM_AcquisitionControlInfo acquisitionControlInfo = {0};


	acquisitionControlInfo.pCamera = pGetCamera;

	isExposureTimeSuccess = GENICAM_createAcquisitionControl(&acquisitionControlInfo, &pAcquisitionCtrl);
	if( isExposureTimeSuccess != 0)
	{
		printf("ExposureTime  fail.\n");
		return -1;
	}
	
	exposureTimeValue = 0.0;
	doubleNode = pAcquisitionCtrl->exposureTime(pAcquisitionCtrl);

	isExposureTimeSuccess = doubleNode.getValue(&doubleNode, &exposureTimeValue);
	if( isExposureTimeSuccess != 0)
	{
		printf("get exposureTime fail.\n");
		return -1;
	}
	else
	{
		printf("before change ,exposureTime is %f\n",exposureTimeValue);
	}	
	
	doubleNode.setValue(&doubleNode, (exposureTimeValue + 2));
	if( isExposureTimeSuccess != 0)
	{
		printf("set exposureTime fail.\n");
		return -1;
	}

	doubleNode.getValue(&doubleNode, &exposureTimeValue);
	if( isExposureTimeSuccess != 0)
	{
		printf("get exposureTime fail.\n");
		return -1;
	}
	else
	{
		printf("after change ,exposureTime is %f\n",exposureTimeValue);
	}

	return 0;
}

static int32_t GENICAM_disconnect(GENICAM_Camera *pGetCamera)
{
	int32_t isDisconnectSuccess;

	isDisconnectSuccess = pGetCamera->disConnect(pGetCamera);
	if( isDisconnectSuccess != 0)
	{
		printf("disconnect fail.\n");
		return -1;
	}
	
	return 0;
}

int32_t CALL_METHOD frameGrabbingProc(void)
{
	int i;
	int32_t ret = -1;
	uint64_t blockId = 0;
	GENICAM_Frame* pFrame;

	for (i = 0; i < 1000; i++)
	{
		if(NULL == pStreamSource)
		{
			return 0;
		}


		ret = pStreamSource->getFrame(pStreamSource, &pFrame, 300);
		if (ret < 0)
		{
			printf("getFrame  fail.\n");
			continue;
		}

		ret = pFrame->valid(pFrame);
		if (ret < 0)
		{
			printf("frame is invalid!\n");

			//Caution：release the frame after using it	
			//注意：使用该帧后需要显示释放
			pFrame->release(pFrame);

			continue;
		}

		printf("get frame id = [%lld] successfully!\n", pFrame->getBlockId(pFrame));

		//Caution：release the frame after using it	
		//注意：使用该帧后需要显示释放
		pFrame->release(pFrame);
	}
	printf("run over \n");
	return 1;
}


// ********************** 这部分处理与SDK操作相机无关，用于显示设备列表 begin*****************************
static void displayDeviceInfo(GENICAM_Camera *pCameraList, int cameraCnt)
{
	GENICAM_Camera *pDisplayCamera = NULL;
	GENICAM_GigECameraInfo GigECameraInfo;
	GENICAM_GigECamera* pGigECamera = NULL;
	int cameraIndex;
	int keyType;
	const char *vendorName = NULL;
	char vendorNameCat[11];
	const char* deviceUserID = NULL;
	char deviceUserIDCat[16];
	const char* ipAddress = NULL;

	int ret = 0;

	/* 打印Title行 */
	printf("\nIdx Type Vendor     Model      S/N             DeviceUserID    IP Address    \n");
	printf("------------------------------------------------------------------------------\n");

	for (cameraIndex = 0; cameraIndex < cameraCnt; cameraIndex++)
	{
		pDisplayCamera = &pCameraList[cameraIndex];
		/* Idx 设备列表的相机索引 最大表示字数：3*/
		printf("%-3d", cameraIndex + 1);

		/* Type 相机的设备类型（GigE，U3V，CL，PCIe）*/
		keyType = pDisplayCamera->getType(pDisplayCamera);
		switch (keyType)
		{
		case typeGige:
			printf(" GigE");
			break;
		case typeUsb3:
			printf(" U3V ");
			break;
		case typeCL:
			printf(" CL  ");
			break;
		case typePCIe:
			printf(" PCIe");
			break;
		default:
			printf("     ");
			break;
		}

		/* VendorName 制造商信息  最大表示字数：10 */
		vendorName = pDisplayCamera->getVendorName(pDisplayCamera);
		if (strlen(vendorName) > 10)
		{
			strncpy(vendorNameCat, vendorName, 7);
			vendorNameCat[7] = '\0';
			strcat(vendorNameCat, "...");
			printf(" %-10.10s", vendorNameCat);
		}
		else
		{
			printf(" %-10.10s", vendorName);
		}

		/* ModeName 相机的型号信息 最大表示字数：10 */
		printf(" %-10.10s", pDisplayCamera->getModelName(pDisplayCamera));

		/* Serial Number 相机的序列号 最大表示字数：15 */
		printf(" %-15.15s", pDisplayCamera->getSerialNumber(pDisplayCamera));

		/* deviceUserID 自定义用户ID 最大表示字数：15 */
		deviceUserID = pDisplayCamera->getName(pDisplayCamera);
		if (strlen(deviceUserID) > 15)
		{
			strncpy(deviceUserIDCat, deviceUserID, 12);
			deviceUserIDCat[12] = '\0';
			strcat(deviceUserIDCat, "...");
			printf(" %-15.15s", deviceUserIDCat);
		}
		else
		{
			//防止console显示乱码,UTF8转换成ANSI进行显示
			memcpy(deviceUserIDCat, deviceUserID, sizeof(deviceUserIDCat));
			printf(" %-15.15s", deviceUserIDCat);
		}

		/* IPAddress GigE相机时获取IP地址 */
		if (keyType == typeGige)
		{
			GigECameraInfo.pCamera = pDisplayCamera;
			ret = GENICAM_createGigECamera(&GigECameraInfo, &pGigECamera);
			if (ret == 0)
			{
				ipAddress = pGigECamera->getIpAddress(pGigECamera);
				if (ipAddress != NULL)
				{
					printf(" %s", pGigECamera->getIpAddress(pGigECamera));
				}

			}
		}

		printf("\n");
	}
	return;
}


static char* trim(char* pStr)
{
	char* pDst = pStr;
	char* pTemStr = NULL;
	int ret = -1;

	if (pDst != NULL)
	{
		pTemStr = pDst + strlen(pStr) - 1;
		//除去字符串首部空格
		while ( *pDst ==' ')
		{
			pDst++;
		}
		//除去字符串尾部空格
		while ((pTemStr > pDst) &&(*pTemStr == ' '))
		{
			*pTemStr-- = '\0';
		}
	}
	return pDst;
}

static int isInputValid(char* pInpuStr)
{
	char numChar;
	char* pStr = pInpuStr;
	while (*pStr != '\0')
	{
		numChar = *pStr;
		if ((numChar > '9') || (numChar < '0'))
		{
			return -1;
		}
		pStr++;
	}
	return 0;
}


static int selectDevice(int cameraCnt)
{
	char inputStr[256] = {0};
	char* pTrimStr;
	int inputIndex = -1;
	int ret = -1;
	char* find = NULL;
	
	/* 提示用户选择 */
	printf("\nPlease input the camera index: ");
	while (1)
	{
		/* 获取输入内容字符串 */
		memset(inputStr, 0, sizeof(inputStr));
		fgets(inputStr, sizeof(inputStr), stdin);
		/* 清空输入缓存 */
		fflush(stdin);
		
		/* fgets比gets多吃一个换行符号，取出换行符号 */
		find = strchr(inputStr, '\n');
		if (find) { *find = '\0'; }
				
		/*除去字符串首尾空格 */
		pTrimStr = trim(inputStr);
		//判断输入字符串是否为数字
		ret = isInputValid(pTrimStr);
		if (ret == 0)
		{
			/* 输入的字符串转换成为数字 */
			inputIndex = atoi(pTrimStr);
			/* 判断用户选择合法性 */
			inputIndex -= 1;//显示的Index是从1开始
			if ((inputIndex >= 0) && (inputIndex < cameraCnt))
			{
				break;
			}
		}

		printf("Input invalid! Please input the camera index: ");
	}
	return inputIndex;
}
// ********************** 这部分处理与SDK操作相机无关，用于显示设备列表 end*****************************


void main()
{
	int32_t ret;
	int32_t cameraIndex = -1;
	GENICAM_System *pSystem = NULL;
	GENICAM_Camera *pCamera = NULL;
	GENICAM_Camera *pCameraList = NULL;
	uint32_t cameraCnt = 0;

	pthread_t threadID;

	// discover camera
	//发现设备
	ret = GENICAM_getSystemInstance(&pSystem);
	if (-1 == ret)
	{
		printf("pSystem is null.\r\n");
		return ;
	}

	ret = pSystem->discovery(pSystem, &pCameraList, &cameraCnt, typeAll);
	if (-1 == ret)
	{
		printf("discovery device fail.\r\n");
		return ;
	}

	if(cameraCnt < 1)
	{
		printf("no Camera is discovered.\r\n");
		return;
	}

	// print camera info (index,Type,vendor name, model,serial number,DeviceUserID,IP Address)
	// 打印相机基本信息（序号,类型,制造商信息,型号,序列号,用户自定义ID,IP地址）
	displayDeviceInfo(pCameraList, cameraCnt);
	// Select the camera 
	// 选择需要连接的相机
	cameraIndex = selectDevice(cameraCnt);
	pCamera = &pCameraList[cameraIndex];

	// connect to camera
	//连接设备
	ret = GENICAM_connect(pCamera);
	if(ret != 0)
	{
		printf("connect cameral failed.\n");
		return;
	}
	
	// create stream source instance
	//创建流对象
	ret = GENICAM_CreateStreamSource(pCamera, &pStreamSource);
	if(ret != 0)
	{
		printf("create stream obj  fail.\r\n");
		return;
	}

	// create frame grabbing thread
	if(pthread_create(&threadID, 0, frameGrabbingProc, NULL) != 0)
	{
		printf("Failed to create getFrame thread!\n");
		return;
	}

	// start grabbing from camera
	//拉流
	ret = GENICAM_startGrabbing(pStreamSource);
	if(ret != 0)
	{
		printf("StartGrabbing  fail.\n");
		return;
	}

	// stop the grabbing thread after 5 second
	//睡眠5秒关闭拉流线程
	sleep(5);
	
	if(pthread_cancel(threadID))
	{
		printf("Failed to cancel getFrame thread!\n");
	}

	// stop grabbing from camera
	GENICAM_stopGrabbing(pStreamSource);

	//close camera
	GENICAM_disconnect(pCamera);

	// close stream
	pStreamSource->release(pStreamSource);
	
	return;
}
