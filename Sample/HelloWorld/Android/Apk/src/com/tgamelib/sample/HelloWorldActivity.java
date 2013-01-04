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
		
		

	    setContentView(mGLView);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_gwar, menu);
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

