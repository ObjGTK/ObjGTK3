include ../extra.mk

SHARED_LIB = ${OGDK3_SHARED_LIB}
STATIC_LIB = ${OGDK3_STATIC_LIB}
FRAMEWORK = ${OGDK3_FRAMEWORK}
LIB_MAJOR = 3
LIB_MINOR = 0

SRCS = OGGdkAppLaunchContext.m \
	OGGdkCursor.m \
	OGGdkDevice.m \
	OGGdkDeviceManager.m \
	OGGdkDeviceTool.m \
	OGGdkDisplay.m \
	OGGdkDisplayManager.m \
	OGGdkDragContext.m \
	OGGdkDrawingContext.m \
	OGGdkFrameClock.m \
	OGGdkGLContext.m \
	OGGdkKeymap.m \
	OGGdkMonitor.m \
	OGGdkScreen.m \
	OGGdkSeat.m \
	OGGdkVisual.m \
	OGGdkWindow.m \
	

INCLUDES = ${SRCS:.m=.h} \
	OGdk3-Umbrella.h

include ../buildsys.mk

LD = ${OBJC}
