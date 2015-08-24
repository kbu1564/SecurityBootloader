package com.example.kimhajin.securitybootloader;
// Splash 구현 부분 //

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;

public class Splash extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        Handler hd = new Handler();
        hd.postDelayed(new Runnable() {
            @Override
            public void run() {
                finish(); //3s후 이미지 닫기
            }
        },2500);
    }
}
