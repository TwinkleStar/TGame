package com.tgamelib.sample;


import android.content.Context;
import android.content.res.AssetManager;

public class TGameAndroid {
	public	TGameAndroid(Context context)
	{
		mContext = context;
	}
	
	private Context	mContext;

 	static{ 
 		System.loadLibrary("HelloWorld"); 
 	} 

 	static native int InitTGame( AssetManager assetManager);
 	
 	static native int DoRender();

	static native int onPause();

	static native int onResume();

	static native int onDestroy();
}
 