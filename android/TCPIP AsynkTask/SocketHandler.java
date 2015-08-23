package Control;

import android.app.Service;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Handler;
import android.os.IBinder;
import android.os.Looper;
import android.os.Message;
import android.os.Parcel;
import android.os.Parcelable;
import android.os.SystemClock;
import android.provider.ContactsContract;
import android.util.Log;

import com.example.hyun.clue.MainActivity;

import java.io.DataInput;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.Serializable;
import java.net.Socket;

/**
 * Created by hyun on 2015-01-26.
 */
public class SocketHandler{

    private Socket clientSocket = null;
    private DataInputStream input = null;
    private DataOutputStream output = null;
    private String readSocketStream = null;

    private static SocketHandler instance;

    public static SocketHandler getInstance()
    {
        if(instance == null) instance = new SocketHandler();
        return instance;
    }

    private SocketHandler()
    {
        try {
            clientSocket = new Socket("210.118.75.144",7788);
            output = new DataOutputStream(clientSocket.getOutputStream());
            input = new DataInputStream(clientSocket.getInputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public String receiveSocket() throws IOException {
        return input.readUTF();
    } // Receive Socket
    public void sendSocket(String s) throws IOException {
        output.writeUTF(s); } // Send Socket

    public void finishSocket() throws IOException {
        clientSocket.close();
        input.close();
        output.close();
        Log.d("f", "dsfasfd");
    }
};

