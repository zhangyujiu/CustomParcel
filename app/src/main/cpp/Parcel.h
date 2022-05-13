#include <malloc.h>
#include <memory.h>
#include <string>

#include <android/log.h>

#define TAG "jack"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);

class Parcel {
private:
    char *mData;
    int mDataPos = 0;
public:
    Parcel();

    ~Parcel();

    void writeInt(int value);

    int readInt();

    void writeChar(char value);

    char readChar();

    void writeString(const char16_t *value, int len);

    std::string readString();

    void setDataPosition(int position);

    void writeInt32(int32_t len);

    template<class T>
    void writeAligned(T len);

    void updatePosition(size_t len);
};