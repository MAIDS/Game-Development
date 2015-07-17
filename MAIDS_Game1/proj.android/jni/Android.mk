LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/Model/Attribute.cpp \
                   ../../Classes/Model/Character.cpp \
                   ../../Classes/Model/HexaGridMap.cpp \
                   ../../Classes/Model/HexaGridMapUnit.cpp \
                   ../../Classes/Model/MapStaticUnit.cpp \
                   ../../Classes/Model/Unit.cpp \
                   ../../Classes/Utils/MAIDSLog.cpp \
                   ../../Classes/Utils/Utils.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../Classes/Model \
					$(LOCAL_PATH)/../../Classes/Interface \
					$(LOCAL_PATH)/../../Classes/Callback \
					$(LOCAL_PATH)/../../Classes/Utils

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
