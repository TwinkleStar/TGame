package com.twinkle.gwar;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class GWarActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		mGLView = new TGameGLSrufaceView(this);
		
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
	
}

