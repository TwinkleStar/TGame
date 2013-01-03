package com.tgamelib.sample;

public class TGameAndroid {
	static{ 
        System.loadLibrary("HelloWorld"); 
    } 

	static native int InitTGame(int nVer);
	static native int DoRender();
}
 