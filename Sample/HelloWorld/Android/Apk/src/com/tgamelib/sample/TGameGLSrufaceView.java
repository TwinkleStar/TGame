package com.tgamelib.sample;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;
import android.annotation.SuppressLint;
import android.content.Context;
import android.view.MotionEvent;

import android.content.res.AssetManager;
import android.graphics.PixelFormat;

@SuppressLint("ViewConstructor")
public class TGameGLSrufaceView extends GLSurfaceView {
	public TGameGLSrufaceView(Context context , TGameAndroid TGame) {
        super(context);
  
        mRenderer	= new TGameRenderer(context , mTGame);

        setRenderer(mRenderer);
        
    }
	
	public boolean onTouchEvent(final MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN) {
       
        }
        return true;
    }

	private TGameAndroid	mTGame;
	private TGameRenderer	mRenderer;
}

class TGameRenderer implements GLSurfaceView.Renderer {
	public TGameRenderer(Context context , TGameAndroid	TGame){
		mContext	= context;
		mTGame		= TGame;
	}
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
			mTGame.InitTGame(mContext.getAssets());
	}
	
	public void onSurfaceChanged(GL10 gl, int w, int h) {

	}
	
	public void onDrawFrame(GL10 gl) {
		mTGame.DoRender();
	}
	
	private Context			mContext;
	private TGameAndroid	mTGame;
}