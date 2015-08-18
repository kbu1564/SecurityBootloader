package com.example.kimhajin.securitybootloader;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;


public class RestartService extends BroadcastReceiver {

    public static final String ACTION_RESTART_PERSISTENTSERVICE
            = "ACTION.Restart.PersistentService";


    @Override
    public void onReceive(Context context, Intent intent) {

        Log.d("RestartService", "RestartService called!!!!!!!!!!!!!!!!!!!!!!!");


        /* 서비스 죽일때 알람으로 다시 서비스 등록 */
        if (intent.getAction().equals(ACTION_RESTART_PERSISTENTSERVICE)) {

            Log.d("RestartService", "Service dead, but resurrection");

            Intent i = new Intent(context, PersistentService.class);
            context.startService(i);
        }

        /* 폰 재부팅할때 서비스 등록 */
        if (intent.getAction().equals(Intent.ACTION_BOOT_COMPLETED)) {

            Log.d("RestartService", "ACTION_BOOT_COMPLETED");

            Intent i = new Intent(context, PersistentService.class);
            context.startService(i);
        }
    }
}
