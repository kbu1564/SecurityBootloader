package com.example.kimhajin.securitybootloader;

import android.content.Intent;
import android.os.Bundle;
import android.app.Activity;
import android.content.DialogInterface;
import android.app.AlertDialog;
import android.widget.Button;
import android.view.View;
import android.content.BroadcastReceiver;
import android.content.IntentFilter;

import android.util.Log;

public class MainActivity extends Activity implements View.OnClickListener{


    BroadcastReceiver receiver;
    Intent intentMyService;

    Button alert;
    Button alert2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        startActivity(new Intent(this, Splash.class)); //app 실행시 먼저 실행되게 함.

        //Background service
        Log.d("MpMainActivity", "service start!!");

        //immortal service 등록
        intentMyService = new Intent(this, PersistentService.class);

        //-------------------------------------------------------------------------//
        // 리시버 등록
        // 실제로는 GPS 구현 없음 클래스 코드 간략화를 위해 GPS 관련 코드 삭제
        receiver = new RestartService();
        try
        {
            IntentFilter mainFilter = new IntentFilter("com.hamon.GPSservice.ssss");

            // 리시버 저장
            registerReceiver(receiver, mainFilter);

            // 서비스 시작
            startService(intentMyService);
        }catch (Exception e){
            Log.d("MpMainActivity", e.getMessage()+"");
            e.printStackTrace();
        }
        //-------------------------------------------------------------------------//

        //------------------------ button 팝업창 설정 --------------------------------//
        //팝업버튼 boot 설정
        alert=(Button)findViewById(R.id.alert); //팝업버튼 아이디
        alert.setOnClickListener(this);

        //팝업버튼 shutdown 설정
        alert2=(Button)findViewById(R.id.alert2); //팝업버튼 아이디
        alert2.setOnClickListener(this);
        //-------------------------------------------------------------------------//

    }

    public void OnDestroy(){
        // 리시버 삭세를 하지 않으면 에러
        Log.d("MpMainActivity", "Service Destroy");
        unregisterReceiver(receiver);

        super.onDestroy();
    }
    //------------------------  button 기능 구현  --------------------------------//

    public void onClick(View view) {
        if(view==alert) { //view가 alert이면 팝업실행 즉 버튼 누르면 팝업창 뜨게 만드는 조건문
            new AlertDialog.Builder(this).setIcon(android.R.drawable.ic_dialog_alert)
                    .setTitle("Booting start") //팝업창 타이틀바
                    .setMessage("컴퓨터를 부팅하시겠습니까??")
                    .setPositiveButton("No", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                           // no 버튼 누르면 팝업창 닫힘 !!

                        }
                    })
                    .setNeutralButton("Yes", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            //부팅 시작 Boot문장을 -> 중계서버로 보내주는 부분 구현 해야함 !!
                        }
                    })
                    .show(); //팝업창 보여줌
        }
        if(view==alert2) { //view가 alert이면 팝업실행 즉 버튼 누르면 팝업창 뜨게 만드는 조건문
            new AlertDialog.Builder(this).setIcon(android.R.drawable.ic_dialog_alert)
                    .setTitle("Shutdown") //팝업창 타이틀바
                    .setMessage("컴퓨터를 종료하시겠습니까?")
                    .setPositiveButton("No", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            //전화면으로 이동
                        }
                    })
                    .setNeutralButton("Yes", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            //shutdown 문장을 -> 중계서버로 보내주는 부분 구현 해야함 !!
                        }
                    })
                    .show(); //팝업창 보여줌
        }

    }
    //-------------------------------------------------------------------------//
}