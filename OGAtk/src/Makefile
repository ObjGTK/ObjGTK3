include ../extra.mk

SHARED_LIB = ${OGATK_SHARED_LIB}
STATIC_LIB = ${OGATK_STATIC_LIB}
FRAMEWORK = ${OGATK_FRAMEWORK}
LIB_MAJOR = 1
LIB_MINOR = 0

SRCS = OGAtkGObjectAccessible.m \
	OGAtkHyperlink.m \
	OGAtkMisc.m \
	OGAtkNoOpObject.m \
	OGAtkNoOpObjectFactory.m \
	OGAtkObject.m \
	OGAtkObjectFactory.m \
	OGAtkPlug.m \
	OGAtkRegistry.m \
	OGAtkRelation.m \
	OGAtkRelationSet.m \
	OGAtkSocket.m \
	OGAtkStateSet.m \
	OGAtkUtil.m \
	

INCLUDES = ${SRCS:.m=.h} \
	OGAtk-Umbrella.h

include ../buildsys.mk

LD = ${OBJC}
