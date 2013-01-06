package com.tgamelib.sample;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.content.res.AssetManager;

public class HelloWorldActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		assetManager = getAssets();
		mGLView = new TGameGLSrufaceView(this , assetManager);

//		mGLView = new TGameGLSrufaceView(this);
		
	//	mGLView.setEGLConfigChooser(8,8,8,8,16,0);
	    setContentView(mGLView);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_hello_world, menu);
		return true;
	}
	@Override
	protected void onPause() {
		super.onPause();
	    mGLView.onPause();
	}
	@Override
    protected void onResume() {
        super.onResume();
        mGLView.onResume();
    }

	private GLSurfaceView 	mGLView;
	static AssetManager assetManager;
}

