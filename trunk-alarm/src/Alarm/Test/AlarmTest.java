package Alarm.Test;


import android.os.Bundle;
import java.util.Calendar;

import java.lang.String;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.app.Activity;
import android.util.Log;

import android.content.Intent;
import android.widget.Toast;



public class AlarmTest extends Activity {
    /** Called when the activity is first created. */
	private static final String TAG = "SomeApp "; 

	protected Toast mToast; 

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.alert_list);
        try {

		Calendar cal = Calendar.getInstance();
		long ms = cal.getTimeInMillis();
		Intent intent        = new Intent(AlarmTest.this, AReceiver.class);
		PendingIntent sender = PendingIntent.getBroadcast(this, 1234567, intent, 0);
		PendingIntent sende2 = PendingIntent.getBroadcast(this, 123123, intent, 0);

		AlarmManager am = (AlarmManager) getSystemService(ALARM_SERVICE);
		am.set(AlarmManager.RTC_WAKEUP, ms+15000, sender); // to be alerted 30 seconds from now
		am.set(AlarmManager.RTC_WAKEUP, ms+10000, sende2); // to be alerted 15 seconds from now
		Toast.makeText(AlarmTest.this, Long.toString(ms)+" Next alerm  in "+Long.toString(1000), Toast.LENGTH_LONG).show();
		/* To show how alarms are cancelled we will create a new 		Intent and a new PendingIntent with the
	 	* same requestCode as the PendingIntent alarm we want to cancel. In this case, it is 1234567.
         	* Note: The intent and PendingIntent have to be the same as the ones used to create the alarms.
         	*/
		/*Intent intent1        = new Intent(AlarmTest.this, AReceiver.class);
		PendingIntent sender1 = PendingIntent.getBroadcast(this, 1234567, intent1, 0);
		AlarmManager am1 = (AlarmManager) getSystemService(ALARM_SERVICE);
		am1.cancel(sender1);*/

        } catch (Exception e) {
        	Log.e(TAG, "ERROR IN CODE:"+e.toString());
        }
    }

}