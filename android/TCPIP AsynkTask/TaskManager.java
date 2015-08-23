package Control;

import android.content.Context;
import android.os.Handler;

import java.io.IOException;

import Model.Data.Dice;
import Model.Logic.Exit;
import Model.Logic.GameAccess;
import Model.Logic.GamePlay;
import Model.Logic.Login;
import Model.Logic.Mode;
import Model.Logic.MyCustom;
import Model.Logic.MyInfo;
import Model.Logic.Ranking;
import Model.Logic.SignUp;

/**
 * Created by hyun on 2015-01-26.
 */
public class TaskManager {

    private SocketHandler sock = null;
    private GameAccess ga=null;
    private Login login = null;
    private SignUp signUp = null;
    private MyInfo myInfo = null;
    private Mode mode = null;
    private Ranking rank = null;
    private GamePlay game = null;
    private Exit exit = null;
    private MyCustom custom = null;
    private Dice dice = null;
    public TaskManager()
    {
        dice = new Dice();
        game = new GamePlay();
        rank = new Ranking();
        mode = new Mode();
        ga = new GameAccess();
        login = new Login();
        signUp = new SignUp();
        myInfo = new MyInfo();
        exit = new Exit();
        mode = new Mode();

    }
    public String exit()
    {
       return exit.exit();
    }

    public String inferenceTransfer()
    {

        return "미구현";

    }
    public String diceThorw()
    {
        return dice.diceThrow();
    }
    public String finalInferenceTransfer()
    {
        return "미구현";
    }

    public String moveCoordinateTransfer(int x,int y)
    {
        return game.moveCoordinateTransfer(x,y);
    }
    public String nextTurn()
    {
        return game.nextTurn();
    }

    public String ranking()
    {
         return rank.ranking();
    }

    ////////////////////////////////////////////////////////////
    public String customMode(int num)
    {

        return mode.customMode(num);

    }
    public String clueMode()
    {
       return mode.clueMode();
    }

    public String createCustom(String s)
    {
        custom = new MyCustom(s);
       return custom.createCustom(s);
    }
    public String deleteMode()
    {
        return "미구현";

    }
    /////////////////////////////////////////////////////
    public String clientMyInfo(String id)
    {
        return myInfo.myInfo(id);

    }
/////////////////////////////////////////////////////////////

    public String gameStart()
    {
        return ga.gameStart();
    }


///////////////////////////////////////////////////////////////////
    public String clientLogin(String id, String password) {return "2$"+id+"$"+password;}


    public void loginError(Context context)
    {
        login.loginError(context);
    }
////////////////////////////////////////
    public String clientSignUp(String id, String password ,String gender,String email )
    {
        return signUp.signUp(id,password,gender,email);
    }
    public void idError(Context context) {signUp.idRepeatError(context);}
    public void passwordError(Context context) {signUp.passwordError(context);}
    public void idSuccess(Context context) {signUp.idRepeatSuccess(context);}
    public void repeatCheck(Context context) {signUp.repeatCheck(context);}
    public void signUpSuccess(Context context) {signUp.signUpSuccess(context);}
    public void passwordError2(Context context) {signUp.passwordError2(context);}
    public void passwordError3(Context context) {signUp.passwordError3(context);}
    public void genderCheck(Context context) {signUp.genderCheck(context);}
}
