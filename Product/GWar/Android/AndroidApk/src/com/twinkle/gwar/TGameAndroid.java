package com.twinkle.gwar;

public class TGameAndroid {
	static{ 
        System.loadLibrary("GWar_Android"); 
    } 

	static native int OnInit();
}
 