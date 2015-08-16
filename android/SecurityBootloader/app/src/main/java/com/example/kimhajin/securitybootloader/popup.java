package com.example.kimhajin.securitybootloader;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.view.Menu;
import android.view.MenuItem;

public class popup extends Activity implements View.OnClickListener {

    Button alert;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_popup);

        alert=(Button)findViewById(R.id.alert); //팝업버튼 아이디
        alert.setOnClickListener(this);
    }
    public void onClick(View view) {
        if(view==alert) { //view가 alert이면 팝업실행 즉 버튼 누르면 팝업창 뜨게 만드는 조건문
            new AlertDialog.Builder(this)
                    .setTitle("Booting start")
                    .setNeutralButton("Yes", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dlg, int sumthin) {
                        }

                    })
                    .show();
        }
    }
}
