package Salat.Android;

import android.content.Context;
import android.content.BroadcastReceiver;
import android.content.Intent;
import android.util.Log;
import android.widget.Toast;


/** All receiver classes must extend BroadcastReceiver */
public class AReceiver extends BroadcastReceiver {

	public void onReceive(Context con, Intent in) {
		//try {
			/* Display an alert */			
			//Toast.makeText(con, "It's Salat time ", Toast.LENGTH_LONG).show();
			Intent i = new Intent(con, SalatAndroid.class);
		    //i.putExtra("message","Wake up.");
		    //i.setClass(con, SalatAndroid.class);
		    i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK|Intent.FLAG_ACTIVITY_SINGLE_TOP);
		    //i.setAction("android.intent.category.START_THE_MUSIC");
		    con.startActivity(i);
		    return;
			//Intent startActivity = new Intent(con, SalatAndroid.class);
			//startActivity.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
			//startActivity.setFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
			//startActivity.setAction("android.intent.category.START_THE_MUSIC");
			//con.startActivity(startActivity);
			//return;
			//((Vibrator)getSystemService(VIBRATOR_SERVICE)).vibrate(300);
		/*} catch (Exception r) {
			Toast.makeText(con, "You were supposed to do something"
					+" now but I can't retrieve what it was.",
					Toast.LENGTH_SHORT).show();
			Log.e("ALARM_RECEIVER", r.toString());
		}*/
	}
}