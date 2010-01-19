package Salat.Android;

import android.content.Context;
import android.content.BroadcastReceiver;
import android.content.Intent;
import android.util.Log;
import android.widget.Toast;


/** All receiver classes must extend BroadcastReceiver */
public class AReceiver extends BroadcastReceiver {

	public void onReceive(Context con, Intent in) {
		try {			
			Intent i = new Intent(con, SalatAndroid.class);
		    i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK|Intent.FLAG_ACTIVITY_SINGLE_TOP);
		    i.setAction("android.intent.category.START_ATHAN");
		    con.startActivity(i);
		    return;			
		} catch (Exception r) {
			
		}
	}
}