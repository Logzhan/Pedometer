#include <jni.h>
#include <string>
#include "Pedometer.h"
extern "C"

JNIEXPORT jstring JNICALL
Java_com_geek_motion_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()

    std::string test = std::string(Pedometer_GetVersion());
    return env->NewStringUTF(test.c_str());
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_geek_motion_MainActivity_pedometerUpdate(JNIEnv *env, jobject thiz, jfloat x, jfloat y,
                                                    jfloat z) {
    // TODO: implement Pedometer_Update()
    float s  = 1000.0f;
    int ax = (int)(x * s);
    int ay = (int)(y * s);
    int az = (int)(z * s);
    return Pedometer_Update(ax, ay, az);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_geek_motion_MainActivity_pedometerInit(JNIEnv *env, jobject thiz) {
    // TODO: implement pedometerInit()
    Pedometer_Init();
}