/*package Control;

import android.os.AsyncTask;
import android.util.Log;

import com.example.hyun.clue.MainActivity;
import android.os.Handler;

import java.io.IOException;

/**
 * Created by hyun on 2015-01-29.

public class MyAsync extends AsyncTask<String, String,String> {
    private boolean threadCancel = true;

    private Handler handler;
    public MyAsync(Handler handler)
    {
        this.handler = handler;
    }



    @Override
    protected void onProgressUpdate(String... progress)
    {
        MainActivity.socketHandler.setReadSocketStream(progress[0]);
    }

    @Override
    protected void onCancelled()
    {
        threadCancel = true;
        publishProgress("끈다");
    }

    @Override
    protected String doInBackground(String... params) {

        String s=null;
        try {
         //   Log.d("Async","before" +  MainActivity.socketHandler.getReadSocketStream());
            MainActivity.socketHandler.sendSocket(params[0]);
            s=MainActivity.socketHandler.receiveSocket();


            MainActivity.socketHandler.setReadSocketStream(s);
      //      Log.d("Async","before" +  MainActivity.socketHandler.getReadSocketStream());

        }
        catch (IOException e) {
            e.printStackTrace();
        }
     //   Log.d("Async", "after");
        return s;

    }

    @Override
    protected void onPostExecute(String aVoid) {
        super.onPostExecute(aVoid);
    }
}
*/