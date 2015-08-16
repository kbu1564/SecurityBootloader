package com.example.kimhajin.securitybootloader;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.app.Activity;
import android.content.DialogInterface;
import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.widget.Button;
import android.widget.Toast;
import android.view.View;
import android.widget.EditText;
import android.support.v4.widget.DrawerLayout;
import android.support.v4.widget.DrawerLayout.DrawerListener;

public class MainActivity extends Activity implements View.OnClickListener{


    Button alert;
    Button alert2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        startActivity(new Intent(this, Splash.class)); //app 실행시 먼저 실행되게 함.

        //팝업버튼 boot 설정
        alert=(Button)findViewById(R.id.alert); //팝업버튼 아이디
        alert.setOnClickListener(this);

        //팝업버튼 shutdown 설정
        alert2=(Button)findViewById(R.id.alert2); //팝업버튼 아이디
        alert2.setOnClickListener(this);
    }
    public void onClick(View view) {
        if(view==alert) { //view가 alert이면 팝업실행 즉 버튼 누르면 팝업창 뜨게 만드는 조건문
            new AlertDialog.Builder(this)
                    .setTitle("Booting start") //팝업창 타이틀바
                    .setPositiveButton("No", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            //전 화면으로 이동
                        }
                    })
                    .setNeutralButton("Yes", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            //부팅 시작
                        }
                    })
                    .show(); //팝업창 보여줌
        }
        if(view==alert2) { //view가 alert이면 팝업실행 즉 버튼 누르면 팝업창 뜨게 만드는 조건문
            new AlertDialog.Builder(this)
                    .setTitle("Shutdown") //팝업창 타이틀바
                    .setPositiveButton("No", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            //전화면으로 이동
                        }
                    })
                    .setNeutralButton("Yes", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            //shutdown
                        }
                    })
                    .show(); //팝업창 보여줌
        }
    }
}