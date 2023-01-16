include ../extra.mk

SHARED_LIB = ${OGGDKPIXBUF_SHARED_LIB}
STATIC_LIB = ${OGGDKPIXBUF_STATIC_LIB}
FRAMEWORK = ${OGGDKPIXBUF_FRAMEWORK}
LIB_MAJOR = 2
LIB_MINOR = 0

SRCS = OGGdkPixbuf.m \
	OGGdkPixbufAnimation.m \
	OGGdkPixbufAnimationIter.m \
	OGGdkPixbufLoader.m \
	OGGdkPixbufSimpleAnim.m \
	

INCLUDES = ${SRCS:.m=.h} \
	OGGdkPixbuf-Umbrella.h

include ../buildsys.mk

LD = ${OBJC}
