#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_geek_motion_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    std::string test = "main ++++";
    return env->NewStringUTF(test.c_str());
}