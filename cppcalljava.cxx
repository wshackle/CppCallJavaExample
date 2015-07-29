#include <jni.h>       /* where everything is defined */
#include <string>
#include <iostream>

int main(int argc, const char **args) {
    JavaVM *jvm;       /* denotes a Java VM */
    JNIEnv *env;       /* pointer to native method interface */
    JavaVMInitArgs vm_args; /* JDK/JRE 6 VM initialization arguments */
    JavaVMOption* options = new JavaVMOption[1];
    options[0].optionString = (char *) "-Djava.class.path=/usr/lib/java:.";
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    /* load and initialize a Java VM, return a JNI interface
     * pointer in env */
    JNI_CreateJavaVM(&jvm, 
		     ((void **) (&env)), 
		     ((void *) (&vm_args)));
    delete options;
    /* invoke the Main.test method using the JNI */
    jclass cls = env->FindClass("Main");
    if(NULL == cls) {
      std::cerr << " Can't find class main" << std::endl;
    } else {
      jmethodID mid = env->GetStaticMethodID(cls, "test", "(I)V");
      if(NULL == mid) {
	std::cerr << "Class Main has no method named test" << std::endl;
      } else {
	env->CallStaticVoidMethod(cls, mid, 100);
      }
    }
    /* We are done. */
    jvm->DestroyJavaVM();
}
