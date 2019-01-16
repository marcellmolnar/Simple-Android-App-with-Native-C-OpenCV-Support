# Simple Android App with Native C++ Support
Shows the camera view in fullscreen in gray. The color convertion done with native C++ OpenCV code.

### SETUP:
1. Download OpenCV for Android pack. Unzip to C:/
2. New Android project with C++ support.
3. New->Import module: path: C:/OpenCV-android-sdk/sdk/java
4. Go to File->Project Structure. On the left, select app. On the top, select Dependencies. Add new Module dependency and select openCVLibrary.
5. App build gradle and OpenCV build gradle should have the same:
	compileSdkVersion buildToolsVerion minSdkVersion and targetSdkVersion.
6. Create new directory in the /src/main folder named "jniLibs".
7. Copy into jniLibs all the folders in C:/OpenCV-android-sdk/sdk/native/libs (arm64-v8a,armeabi,etc.)
8. Modify CMakeLists.txt with the following lines:
	To the beginning: 
		
		set(pathToOpenCV C:\\OpenCV-android-sdk)
		set(pathToProject C:\\Users\\Marci\\Desktop\\other_stuff\\Android/OpenCV)
	
	After "cmake_minimum_requires":
		
		#Two sets suggested by Bruno Alexandre Krinski 20160825
		set(CMAKE VERBOSE MAKEFILE on)
		set(CMAKE CXX FLAGS "{CMAKE CXX FLAGS} -std=gnu++11")
		
		include_directories(${pathToOpenCV}\\sdk\\native\\jni\\include)
		
	After "add_library":	
		
		# Adding OpenCV
		add_library(lib_opencv SHARED IMPORTED)
		set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathToProject}\\app\\src\\main\\jniLibs\\${ANDROID_ABI}\\libopencv_java3.so)
	
	Modify last command "target_link_libraries" to:
		
		target_link_libraries( # Specifies the target library.
                       native-lib
		
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
		
                        lib_opencv )
		
9. Try to Sync and Compile.

### Sources I used:
https://stackoverflow.com/questions/38958876/can-opencv-for-android-leverage-the-standard-c-support-to-get-native-build-sup
https://www.youtube.com/watch?v=Z2vrioEr9OI
https://www.youtube.com/watch?v=0fdIiOqCz3o