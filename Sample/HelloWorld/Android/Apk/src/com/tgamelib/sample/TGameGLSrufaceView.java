package com.tgamelib.sample;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;
import android.annotation.SuppressLint;
import android.content.Context;
import android.view.MotionEvent;

import android.content.res.AssetManager;

@SuppressLint("ViewConstructor")
public class TGameGLSrufaceView extends GLSurfaceView {
	public TGameGLSrufaceView(Context context , AssetManager assetMgr) {
        super(context);
        mRenderer	= new TGameRenderer(context);
        setRenderer(mRenderer);
        
        
    }
	
	public boolean onTouchEvent(final MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN) {
       
        }
        return true;
    }
	
	private TGameRenderer	mRenderer;


	
}
	class TGameRenderer implements GLSurfaceView.Renderer {
		public TGameRenderer(Context context){

		
			mAssetMgr = context.getAssets();
	
		}
	    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
	    	
			InitTGame( mAssetMgr );
			
	    }
	
	    public void onSurfaceChanged(GL10 gl, int w, int h) {
	//	    	gl.glOrthof(0,w, h, 0, 1.0f, -1.0f);
	    	
	    }
	
	    public void onDrawFrame(GL10 gl) {
	    	
			DoRender();
	    }
	
	    static{ 
	    System.loadLibrary("HelloWorld"); 
		} 	
		static AssetManager	 mAssetMgr;
		static native int InitTGame(AssetManager assetManager);
	//	static native int InitTGame(int a);
		static native int DoRender();
	//	private TGameAndroid	mTGame;
	}