#include <jni.h>
#include <string>
#include "Parcel.h"
#include <android/log.h>

extern "C"
JNIEXPORT jlong JNICALL
Java_com_jk_parcel_CustomParcel_nativeCreate(JNIEnv *env, jobject thiz) {
    auto *parcel = new Parcel();
    return reinterpret_cast<jlong>(parcel);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jk_parcel_CustomParcel_nativeSetDataPosition(JNIEnv *env, jobject thiz, jlong native_ptr, jint position) {
    auto *parcel = reinterpret_cast<Parcel *>(native_ptr);
    LOGE("position = %d", position)
    parcel->setDataPosition(position);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jk_parcel_CustomParcel_nativeWriteInt(JNIEnv *env, jobject thiz, jlong native_ptr, jint value) {
    auto *parcel = reinterpret_cast<Parcel *>(native_ptr);
    LOGE("value = %d", value)
    parcel->writeInt(value);
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_jk_parcel_CustomParcel_nativeReadInt(JNIEnv *env, jobject thiz, jlong native_ptr) {
    auto *parcel = reinterpret_cast<Parcel *>(native_ptr);
    int result = parcel->readInt();
    return result;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_jk_parcel_CustomParcel_nativeWriteChar(JNIEnv *env, jobject thiz, jlong native_ptr, jchar value) {
    auto *parcel = reinterpret_cast<Parcel *>(native_ptr);
    LOGE("value = %d", value)
    parcel->writeChar(value);
}
extern "C"
JNIEXPORT jchar JNICALL
Java_com_jk_parcel_CustomParcel_nativeReadChar(JNIEnv *env, jobject thiz, jlong native_ptr) {
    auto *parcel = reinterpret_cast<Parcel *>(native_ptr);
    return parcel->readChar();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jk_parcel_CustomParcel_nativeWriteString(JNIEnv *env, jobject thiz, jlong native_ptr, jstring value) {
    auto *parcel = reinterpret_cast<Parcel *>(native_ptr);
    const char *str = env->GetStringUTFChars(value, nullptr);
    if (str) {
        jsize length = env->GetStringLength(value);
        parcel->writeString(reinterpret_cast<const char16_t *>(str), length);
        env->ReleaseStringUTFChars(value, str);
    }
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_jk_parcel_CustomParcel_nativeReadString(JNIEnv *env, jobject thiz, jlong native_ptr) {
    auto *parcel = reinterpret_cast<Parcel *>(native_ptr);
    const std::string string = parcel->readString();
    const char *data = string.c_str();
    jstring result = env->NewStringUTF(data);
    return result;
}