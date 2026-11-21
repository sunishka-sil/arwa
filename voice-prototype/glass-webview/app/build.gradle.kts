plugins {
    id("com.android.application")
}

android {
    namespace = "com.worn.glassview"
    compileSdk = 35

    defaultConfig {
        applicationId = "com.worn.glassview"
        minSdk = 28          // M6 glasses run Android 9 (API 28)
        targetSdk = 35
        versionCode = 2
        versionName = "1.1"
        ndk { abiFilters += listOf("arm64-v8a") } // the glasses are arm64; keeps the APK small
    }
}

dependencies {
    // Offline speech recognition on the glasses (glasses microphone, no internet).
    implementation("com.alphacephei:vosk-android:0.3.47@aar")
    implementation("net.java.dev.jna:jna:5.13.0@aar")
}
