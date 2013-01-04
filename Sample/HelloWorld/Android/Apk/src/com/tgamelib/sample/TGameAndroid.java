package com.tgamelib.sample;

import android.content.res.AssetManager;

public class TGameAndroid {
	static{ 
        System.loadLibrary("HelloWorld"); 
    } 

	static native int InitTGame(int nVer , AssetManager assetManager);
	static native int DoRender();
}
 