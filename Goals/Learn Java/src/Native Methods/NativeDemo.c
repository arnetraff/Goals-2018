//
#include <jni.h>
#include "NativeDemo.h"
#include <stdio.h>
#include <stdlib.h>



JNIEXPORT void JNICALL Java_NativeDemo_test(JNIEnv* env,jobject obj)
{
    jclass cls;
    jfieldID fid;
    jint i;
    printf("Starting native method.\n");
    cls = (*env)->GetObjectClass(env,obj);
    fid = (*env)->GetFieldID(env,cls,"i","I");
    if (fid == 0) {printf("Could not get field ID.\n"); return;}
    i = (*env)->GetIntField(env,obj,fid);
    printf("i = %d\n",i);

    (*env)->SetIntField(env,obj,fid,2*i);
    printf("Ending Native Method.\n");
   
}
