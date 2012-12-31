package com.twinkle.gwar;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;
import android.content.Context;
import android.view.MotionEvent;



public class TGameGLSrufaceView extends GLSurfaceView {
	public TGameGLSrufaceView(Context context) {
        super(context);
        mRenderer = new TGameRenderer();
        setRenderer(mRenderer);
    }
	
	public boolean onTouchEvent(final MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN) {
       
        }
        return true;
    }

	TGameRenderer mRenderer;
}

class TGameRenderer implements GLSurfaceView.Renderer {
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
      //  nativeInit();
    }

    public void onSurfaceChanged(GL10 gl, int w, int h) {
        //gl.glViewport(0, 0, w, h);
       // nativeResize(w, h);
    }

    public void onDrawFrame(GL10 gl) {
      //  nativeRender();
    }

   // private static native void nativeInit();
    //private static native void nativeResize(int w, int h);
    //private static native void nativeRender();
    //private static native void nativeDone();
}
