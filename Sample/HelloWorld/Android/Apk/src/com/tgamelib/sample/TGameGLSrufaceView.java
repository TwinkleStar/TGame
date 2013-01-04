package com.tgamelib.sample;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;
import android.content.Context;
import android.view.MotionEvent;

import android.content.res.AssetManager;

public class TGameGLSrufaceView extends GLSurfaceView {
	public TGameGLSrufaceView(Context context , AssetManager assetMgr) {
        super(context);
        mRenderer	= new TGameRenderer(assetMgr);
		

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
	public TGameRenderer(AssetManager assetMgr){
		mTGame		= new TGameAndroid();
		
		mTGame.InitTGame(0 , assetMgr);
	}
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		
    }

    public void onSurfaceChanged(GL10 gl, int w, int h) {
     
    }

    public void onDrawFrame(GL10 gl) {
		mTGame.DoRender();
    }

	private TGameAndroid	mTGame;
}
