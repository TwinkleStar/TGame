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
		
		mTGame = new TGameAndroid(this);

		mGLView = new TGameGLSrufaceView(this ,mTGame);

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
		mTGame.onPause();
	}
	@Override
    protected void onResume() {
        super.onResume();
        mGLView.onResume();
		mTGame.onResume();
    }
	 @Override
    protected void onDestroy(){
    	
     	
		super.onDestroy();
    }


	public	TGameAndroid	mTGame;

	private GLSurfaceView 	mGLView;
}

